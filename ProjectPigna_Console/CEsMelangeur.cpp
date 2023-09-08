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
	if (DAQmxCreateDOChan(m_tache_lecture_tor, "Dev1/port1", "", DAQmx_Val_ChanForAllLines) < 0)
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
	if (DAQmxCreateDOChan(m_tache_lecture_ana, "Dev1/ai1", "", DAQmx_Val_ChanForAllLines) < 0)
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
	if (DAQmxReadDigitalScalarU32(m_tache_lecture_tor, 1000, &lecture_tor_value, NULL) < 0)
		return -1;

	return 0;
}

int32 CEsMelangeur::majSorties()
{
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

#pragma region  Setters
void CEsMelangeur::setVannePVCBase(bool etat) {
	// Implémentation à compléter
}

void CEsMelangeur::setVannePVCBaseFD(bool etat) {
	// Implémentation à compléter
}

void CEsMelangeur::setVannePlastifiant(bool etat) {
	// Implémentation à compléter
}

void CEsMelangeur::setVanneLubrifiant(bool etat) {
	// Implémentation à compléter
}

void CEsMelangeur::setVanneVidange(bool etat) {
	// Implémentation à compléter
}

void CEsMelangeur::setMalaxeur(bool etat) {
	// Implémentation à compléter
}

void CEsMelangeur::setEvacuation(bool etat) {
	// Implémentation à compléter
}

void CEsMelangeur::setVoyantRouge(bool etat) {
	// Implémentation à compléter
}
#pragma endregion
