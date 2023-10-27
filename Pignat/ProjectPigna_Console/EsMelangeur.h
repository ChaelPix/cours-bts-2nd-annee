#ifndef _ESMELANGEUR_
#define _ESMELANGEUR_

#include "NIDAQmx.h"
#include <string>
#include <iostream>
#include <Windows.h>

class CEsMelangeur
{
private:
		// masse de produit
	int m_poids;
		// image des capteurs
	bool m_capteur_bas_R1;			// réservoir 1b                                                                                                                                                                                                                                                                                                                                                                       
	bool m_capteur_bas_R2;			// réservoir 2
	bool m_capteur_bas_R3;			// réservoir 3
	bool m_capteur_niveau_bas;		// cuve de refroidissement
	bool m_capteur_niveau_haut;		// cuve de refroidissement
	bool m_marche;					// panneau de commande
	bool m_arret;					// panneau de commande
	bool m_manuel_auto;				// panneau de commande
		// image des actionneurs
	bool m_vanne_pvc_base;			// vanne réservoir R1
	bool m_vanne_pvc_base_FD;		// vanne réservoir R1 Faible Débit
	bool m_vanne_plastifiant;		// vanne réservoir R2
	bool m_vanne_lubrifiant;		//vanne réservoir R3
	bool m_vanne_vidange;			// vidange malaxeur
	bool m_malaxeur;				// agitateur malaxeur
	bool m_evacuation;				// pompe vidange cuve
	bool m_voyant_rouge;			//panneau de commande

	void initVariables();
		// identificateurs taches DAQmx
			// acquisition des données analogiques
	TaskHandle m_tache_lecture_ana;
			// acquisition des données numériques
	TaskHandle m_tache_lecture_tor;
			// restitution des données numériques
	TaskHandle m_tache_ecriture_tor;
public:
		/* Constructeur
		**	initialise les attributs à 0
		*/
	CEsMelangeur();
	
		/*
		** Initialisation de l'interface d'E/S NiDAQ
		*/
	int32 initEsMelangeur();
	
		/*
		** Clotûre de l'interface d'E/S NiDAQ
		*/
	int32 fermerEsMelangeur();
	
		/*
		** Acquisition des données analogiques et numériques
		** L'automaticien demande à ce que TOUTES les entrées
		** soient acquises au même moment.
		** Donc sur un port 8 bits on lit un octet.
		*/
	int32 lireEntrees();
	
		/*
		** Restitution des données numériques
		** L'automaticien demande à ce que TOUTES les sorties
		** soient mises à jour au même moment.
		** Donc sur un port 8 bits on écrit un octet.
		*/
	int32 majSorties();
	
		/* Accesseurs
		** Permettent d'obtenir les valeurs des attributs privés de la classe
		** Dans ce modèle seule l'image des données en entrée a un sens.
		*/
	int getPoids();
	bool getCapteurBasR1();
	bool getCapteurBasR2();
	bool getCapteurBasR3();
	bool getCapteurNiveauBas();
	bool getCapteurNiveauHaut();
	bool getMarche();
	bool getArret();
	bool getManuelAuto();
	
		/* Mutateurs
		** Permettent d'affecter une valeur aux attributs privés de la classe
		** Dans ce modèle seule l'image des données en sortie a un sens.
		*/
	void setVannePVCBase(bool etat);
	void setVannePVCBaseFD(bool etat);
	void setVannePlastifiant(bool etat);
	void setVanneLubrifiant(bool etat);
	void setVanneVidange(bool etat);
	void setMalaxeur(bool etat);
	void setEvacuation(bool etat);
	void setVoyantRouge(bool etat);
	
		/* Récupération du texte correspondant au numéro d'erreur retouné par les fonctions DAQmx
		** On passe le numéro d'erreur
		** On récupère la chaîne en string
		*/

	void lancerCycleFabrication(int masse_pvc_base, int masse_plastifiant, int masse_lubrifiant, int temps_malaxage, int temps_refroidissement);

	std::string texteErreur(int32 code);
};
#endif
