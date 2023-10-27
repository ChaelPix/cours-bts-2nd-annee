#include "EsMelangeur.h"


CEsMelangeur::CEsMelangeur()
{
	initVariables();

	//int32 error = initEsMelangeur();
	//if (error != 0)
	//{
	//	throw(texteErreur(error));
	//}
}

void CEsMelangeur::lancerCycleFabrication(int masse_pvc_base, int masse_plastifiant, int masse_lubrifiant, int temps_malaxage, int temps_refroidissement)
{

	enum class Etats {AttenteMarche, VersementPvc, VersementPlastifiant, VersementLubrifiant, Malaxage, Vidange, Refroidissement, Evacuation, Fin};

	Etats nEtat = Etats::AttenteMarche;
	int duree_refroid = 0;
	int duree_malax = 0;
	bool running = true;

	while (running)
	{
		lireEntrees();
		system("cls");

		switch (nEtat) {
		case Etats::AttenteMarche:
			std::cout << "Apuyez sur Marche pour commencer";
			if (m_marche)
				nEtat = Etats::VersementPvc;
			break;

		case Etats::VersementPvc:
			if((m_poids >= masse_pvc_base))
				nEtat = Etats::VersementPlastifiant;
			std::cout << "Poids (g) : " << getPoids() << "/" << masse_pvc_base;
			break;

		case Etats::VersementPlastifiant:
			if(m_poids >= masse_pvc_base + masse_plastifiant)
				nEtat = Etats::VersementLubrifiant;
			std::cout << "Poids (g) : " << getPoids() << "/" << masse_pvc_base + masse_plastifiant;
			break;

		case Etats::VersementLubrifiant:
			if (m_poids >= masse_pvc_base + masse_plastifiant + masse_lubrifiant)
				nEtat = Etats::Malaxage;
			std::cout << "Poids (g) : " << getPoids() << "/" << masse_pvc_base + masse_plastifiant + masse_lubrifiant;
			break;

		case Etats::Malaxage:
			if(duree_malax >= temps_malaxage)
				nEtat = Etats::Vidange;
			std::cout << "Malax : " << duree_malax << " / " << temps_malaxage << "s";
			break;

		case Etats::Vidange:
			if (m_poids <= 20)
				nEtat = Etats::Refroidissement;
			std::cout << "Poids (g) : " << getPoids();
			break;

		case Etats::Refroidissement:
			if (duree_refroid >= temps_refroidissement)
				nEtat = Etats::Evacuation;
			std::cout << "Refroidissement : " << duree_refroid << " / " << temps_refroidissement << "s";
			break;

		case Etats::Evacuation:
			if (m_capteur_niveau_bas == 0)
				nEtat = Etats::Fin;
			std::cout << "Evacuation";
			break;

		default:
			running = false;
		}


		m_vanne_pvc_base = (nEtat == Etats::VersementPvc);
		m_vanne_plastifiant = (nEtat == Etats::VersementPlastifiant);
		m_vanne_lubrifiant = (nEtat == Etats::VersementLubrifiant);
		if (nEtat == Etats::Malaxage)
		{
			duree_malax++;
			Sleep(1000);
		}
		m_vanne_vidange = (nEtat == Etats::Vidange);
		if (nEtat == Etats::Refroidissement)
		{
			duree_refroid++;
			Sleep(1000);
		}
		m_evacuation = (nEtat == Etats::Evacuation);
		m_malaxeur = (nEtat == Etats::Malaxage || nEtat == Etats::VersementLubrifiant);

		majSorties();
	}

}

void CEsMelangeur::initVariables()
{
	m_poids = 0;

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
	TaskHandle tempETORHandle;
	if (DAQmxCreateTask("", &tempETORHandle) < 0)
	{
		//std::cout << "ERROR Create Task" << std::endl;
		return -1;
	}
	m_tache_ecriture_tor = tempETORHandle;

	if (DAQmxCreateDOChan(m_tache_ecriture_tor, "Dev1/port0", "", DAQmx_Val_ChanForAllLines) < 0)
	{
		//std::cout << "ERROR Create DigitalOut" << std::endl;
		return -2;
	}
	if (DAQmxStartTask(m_tache_ecriture_tor) < 0)
	{
		//std::cout << "ERROR Start Task" << std::endl;
		return -3;
	}

	//Digital In
	TaskHandle tempLTORHandle;

	if (DAQmxCreateTask("", &tempLTORHandle) < 0)
	{
		//std::cout << "ERROR Create Task" << std::endl;
		return -4;
	}
	m_tache_lecture_tor = tempLTORHandle;

	if (DAQmxCreateDIChan(m_tache_lecture_tor, "Dev1/port1", "", DAQmx_Val_ChanForAllLines) < 0)
	{
		//std::cout << "ERROR Create DigitalOut" << std::endl;
		return -5;
	}
	if (DAQmxStartTask(m_tache_lecture_tor) < 0)
	{
		//std::cout << "ERROR Start Task" << std::endl;
		return -6;
	}

	//Analog In
	TaskHandle tempLAHandle;
	if (DAQmxCreateTask("", &tempLAHandle) < 0)
	{
		//std::cout << "ERROR Create Task" << std::endl;
		return -7;
	}
	m_tache_lecture_ana = tempLAHandle;

	if (DAQmxCreateAIVoltageChan(m_tache_lecture_ana, "Dev1/ai0", "", DAQmx_Val_RSE, -10.0, 0.0, DAQmx_Val_Volts, ""))
	{
		//std::cout << "ERROR Create DigitalOut" << std::endl;
		return -8;
	}
	if (DAQmxStartTask(m_tache_lecture_ana) < 0)
	{
		//std::cout << "ERROR Start Task" << std::endl;
		return -9;
	}

	return 0;
}

std::string CEsMelangeur::texteErreur(int32 code)
{
	switch (code)
	{
		case -1: return "ERROR Create Task : m_tache_ecriture_tor";
		case -2: return "ERROR Create DigitalOut : m_tache_ecriture_tor";
		case -3: return "ERROR Start Task : m_tache_ecriture_tor";
		case -4: return "ERROR Create Task : m_tache_lecture_tor";
		case -5: return "ERROR Create DigitalIn : m_tache_lecture_tor";
		case -6: return "ERROR Start Task : m_tache_lecture_tor";
		case -7: return "ERROR Create Task : m_tache_lecture_ana";
		case -8: return "ERROR Create DAQmxCreateAIVoltageChan : m_tache_lecture_ana";
		case -9: return "ERROR Start Task : m_tache_lecture_ana";
		case -10: return "ERROR Write Task : m_tache_ecriture_tor";

		default: return "ERROR UNKOWN";
	}
}

int32 CEsMelangeur::fermerEsMelangeur()
{
	//Digital out
	if (DAQmxStopTask(m_tache_ecriture_tor) < 0)
	{
		std::cout << "ERROR Stop Task" << std::endl;
		return -11;
	}
	if (DAQmxClearTask(m_tache_ecriture_tor) < 0)
	{
		std::cout << "ERROR Clear Task" << std::endl;
		return -12;
	}

	//Digital In
	if (DAQmxStopTask(m_tache_lecture_tor) < 0)
	{
		std::cout << "ERROR Stop Task" << std::endl;
		return -13;
	}
	if (DAQmxClearTask(m_tache_lecture_tor) < 0)
	{
		std::cout << "ERROR Clear Task" << std::endl;
		return -14;
	}

	//Analog In
	if (DAQmxStopTask(m_tache_lecture_ana) < 0)
	{
		std::cout << "ERROR Stop Task" << std::endl;
		return -15;
	}
	if (DAQmxClearTask(m_tache_lecture_ana) < 0)
	{
		std::cout << "ERROR Clear Task" << std::endl;
		return -16;
	}

	return 1;
}

int32 CEsMelangeur::lireEntrees()
{
	//Read analog
	float64 weightV;
	DAQmxReadAnalogScalarF64(m_tache_lecture_ana, 1000, &weightV, NULL);

	m_poids = ((weightV * 2000) / 10) * -1;

	//Read digital in
	uInt32 lecture_tor_value;
	if (DAQmxReadDigitalScalarU32(m_tache_lecture_tor, 1000, &lecture_tor_value, NULL) < 0)
		return -17;

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
		return -10;

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


//	m_capteur_bas_R1 = false;
//m_capteur_bas_R2 = false;
//m_capteur_bas_R3 = false;
//m_capteur_niveau_bas = false;
//m_capteur_niveau_haut = false;
//m_marche = false;
//m_arret = false;
//m_manuel_auto = false;