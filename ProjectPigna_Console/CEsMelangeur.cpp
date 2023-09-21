#include "EsMelangeur.h"


CEsMelangeur::CEsMelangeur()
{
	initVariables();
	initEsMelangeur();
	

}

void CEsMelangeur::initVariables()
{
	m_poids = 0;
	m_capteur_bas_R1 = false;
	m_capteur_bas_R2 = false;
	m_capteur_bas_R3 = false;
	m_capteur_niveau_bas = false;
	m_capteur_niveau_haut = false;
	m_marche = false;
	m_arret = false;
	m_manuel_auto = false;
	m_vanne_pvc_base = false;
	m_vanne_pvc_base_FD = false;
	m_vanne_plastifiant = false;
	m_vanne_lubrifiant = false;
	m_vanne_vidange = false;
	m_malaxeur = false;
	m_evacuation = false;
	m_voyant_rouge = false;
}

int32 CEsMelangeur::initEsMelangeur()
{
	//Digital out
	if (DAQmxCreateTask("", &m_tache_ecriture_tor) < 0)
	{
		std::cout << "ERROR Create Task" << std::endl;
		return -1;
	}
	if (DAQmxCreateDOChan(m_tache_ecriture_tor, "Dev1/port0", "", DAQmx_Val_ChanForAllLines) < 0)
	{
		std::cout << "ERROR Create DigitalOut" << std::endl;
		return -1;
	}
	if (DAQmxStartTask(m_tache_ecriture_tor) < 0)
	{
		std::cout << "ERROR Start Task" << std::endl;
		return -1;
	}

	//Digital In
	if (DAQmxCreateTask("", &m_tache_lecture_tor) < 0)
	{
		std::cout << "ERROR Create Task" << std::endl;
		return -1;
	}
	if (DAQmxCreateDIChan(m_tache_lecture_tor, "Dev1/port1", "", DAQmx_Val_ChanForAllLines) < 0)
	{
		std::cout << "ERROR Create DigitalOut" << std::endl;
		return -1;
	}
	if (DAQmxStartTask(m_tache_lecture_tor) < 0)
	{
		std::cout << "ERROR Start Task" << std::endl;
		return -1;
	}

	//Analog In
	if (DAQmxCreateTask("", &m_tache_lecture_ana) < 0)
	{
		std::cout << "ERROR Create Task" << std::endl;
		return -1;
	}
	if (DAQmxCreateAIVoltageChan(m_tache_lecture_ana, "Dev1/ai0", "", DAQmx_Val_RSE, 0.0, 5.0, DAQmx_Val_Volts, ""))
	{
		std::cout << "ERROR Create DigitalOut" << std::endl;
		return -1;
	}
	if (DAQmxStartTask(m_tache_lecture_ana) < 0)
	{
		std::cout << "ERROR Start Task" << std::endl;
		return -1;
	}

	return 0;
}

int32 CEsMelangeur::fermerEsMelangeur()
{
	//Digital out
	if (DAQmxStopTask(m_tache_ecriture_tor) < 0)
	{
		std::cout << "ERROR Stop Task" << std::endl;
		return -1;
	}
	if (DAQmxClearTask(m_tache_ecriture_tor) < 0)
	{
		std::cout << "ERROR Clear Task" << std::endl;
		return -1;
	}

	//Digital In
	if (DAQmxStopTask(m_tache_lecture_tor) < 0)
	{
		std::cout << "ERROR Stop Task" << std::endl;
		return -1;
	}
	if (DAQmxClearTask(m_tache_lecture_tor) < 0)
	{
		std::cout << "ERROR Clear Task" << std::endl;
		return -1;
	}

	//Analog In
	if (DAQmxStopTask(m_tache_lecture_ana) < 0)
	{
		std::cout << "ERROR Stop Task" << std::endl;
		return -1;
	}
	if (DAQmxClearTask(m_tache_lecture_ana) < 0)
	{
		std::cout << "ERROR Clear Task" << std::endl;
		return -1;
	}

	return 1;
}

int32 CEsMelangeur::lireEntrees()
{
	//Read analog
	float64 weight;
	DAQmxReadAnalogScalarF64(m_tache_lecture_ana, 1000, &weight, NULL);
	m_poids = weight; //float to int

	//Read digital in
	uInt32 lecture_tor_value;
	if (DAQmxReadDigitalScalarU32(m_tache_lecture_tor, 1000, &lecture_tor_value, NULL) < 0)
		return -1;

	m_capteur_bas_R1 = (lecture_tor_value & (1 << 0)) != 0;       // bit 0
	m_capteur_bas_R2 = (lecture_tor_value & (1 << 1)) != 0;       // bit 1
	m_capteur_bas_R3 = (lecture_tor_value & (1 << 2)) != 0;       // bit 2
	m_capteur_niveau_bas = (lecture_tor_value & (1 << 3)) != 0;   // bit 3
	m_capteur_niveau_haut = (lecture_tor_value & (1 << 4)) != 0;  // bit 4
	m_marche = (lecture_tor_value & (1 << 5)) != 0;               // bit 5
	m_arret = (lecture_tor_value & (1 << 6)) != 0;                // bit 6
	m_manuel_auto = (lecture_tor_value & (1 << 7)) != 0;          // bit 7

	return 0;
}

int32 CEsMelangeur::majSorties()
{
	uInt32 ecriture_tor_value = 0;

	ecriture_tor_value |= (m_vanne_pvc_base << 0);			// bit 0
	ecriture_tor_value |= (m_vanne_pvc_base_FD << 1);		// bit 1
	ecriture_tor_value |= (m_vanne_plastifiant << 2);		// bit 2
	ecriture_tor_value |= (m_vanne_lubrifiant << 3);		// bit 3
	ecriture_tor_value |= (m_vanne_vidange << 4);			// bit 4
	ecriture_tor_value |= (m_malaxeur << 5);				// bit 5
	ecriture_tor_value |= (m_evacuation << 6);              // bit 6
	ecriture_tor_value |= (m_voyant_rouge << 7);			// bit 7

	if (DAQmxWriteDigitalScalarU32(m_tache_ecriture_tor, true, 10, ecriture_tor_value, NULL) < 0)
		return -1;

	return 0;
}

#pragma region Accesseurs
int CEsMelangeur::getPoids() {
	return m_poids;
}

bool CEsMelangeur::getCapteurBasR1() {
	return m_capteur_bas_R1;
}

bool CEsMelangeur::getCapteurBasR2() {
	return m_capteur_bas_R2;
}

bool CEsMelangeur::getCapteurBasR3() {
	return m_capteur_bas_R3;
}

bool CEsMelangeur::getCapteurNiveauBas() {
	return m_capteur_niveau_bas;
}

bool CEsMelangeur::getCapteurNiveauHaut() {
	return m_capteur_niveau_haut;
}

bool CEsMelangeur::getMarche() {
	return m_marche;
}

bool CEsMelangeur::getArret() {
	return m_arret;
}

bool CEsMelangeur::getManuelAuto() {
	return m_manuel_auto;
}
#pragma endregion

#pragma region Mutateurs
void CEsMelangeur::setVannePVCBase(bool etat) {
	m_vanne_pvc_base = etat;
}

void CEsMelangeur::setVannePVCBaseFD(bool etat) {
	m_vanne_pvc_base_FD = etat;
}

void CEsMelangeur::setVannePlastifiant(bool etat) {
	m_vanne_plastifiant = etat;
}

void CEsMelangeur::setVanneLubrifiant(bool etat) {
	m_vanne_lubrifiant = etat;
}

void CEsMelangeur::setVanneVidange(bool etat) {
	m_vanne_vidange = etat;
}

void CEsMelangeur::setMalaxeur(bool etat) {
	m_malaxeur = etat;
}

void CEsMelangeur::setEvacuation(bool etat) {
	m_evacuation = etat;
}

void CEsMelangeur::setVoyantRouge(bool etat) {
	m_voyant_rouge = etat;
}
#pragma endregion
