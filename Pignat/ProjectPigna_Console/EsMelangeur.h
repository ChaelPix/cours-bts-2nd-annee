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
	bool m_capteur_bas_R1;			// r�servoir 1b                                                                                                                                                                                                                                                                                                                                                                       
	bool m_capteur_bas_R2;			// r�servoir 2
	bool m_capteur_bas_R3;			// r�servoir 3
	bool m_capteur_niveau_bas;		// cuve de refroidissement
	bool m_capteur_niveau_haut;		// cuve de refroidissement
	bool m_marche;					// panneau de commande
	bool m_arret;					// panneau de commande
	bool m_manuel_auto;				// panneau de commande
		// image des actionneurs
	bool m_vanne_pvc_base;			// vanne r�servoir R1
	bool m_vanne_pvc_base_FD;		// vanne r�servoir R1 Faible D�bit
	bool m_vanne_plastifiant;		// vanne r�servoir R2
	bool m_vanne_lubrifiant;		//vanne r�servoir R3
	bool m_vanne_vidange;			// vidange malaxeur
	bool m_malaxeur;				// agitateur malaxeur
	bool m_evacuation;				// pompe vidange cuve
	bool m_voyant_rouge;			//panneau de commande

	void initVariables();
		// identificateurs taches DAQmx
			// acquisition des donn�es analogiques
	TaskHandle m_tache_lecture_ana;
			// acquisition des donn�es num�riques
	TaskHandle m_tache_lecture_tor;
			// restitution des donn�es num�riques
	TaskHandle m_tache_ecriture_tor;
public:
		/* Constructeur
		**	initialise les attributs � 0
		*/
	CEsMelangeur();
	
		/*
		** Initialisation de l'interface d'E/S NiDAQ
		*/
	int32 initEsMelangeur();
	
		/*
		** Clot�re de l'interface d'E/S NiDAQ
		*/
	int32 fermerEsMelangeur();
	
		/*
		** Acquisition des donn�es analogiques et num�riques
		** L'automaticien demande � ce que TOUTES les entr�es
		** soient acquises au m�me moment.
		** Donc sur un port 8 bits on lit un octet.
		*/
	int32 lireEntrees();
	
		/*
		** Restitution des donn�es num�riques
		** L'automaticien demande � ce que TOUTES les sorties
		** soient mises � jour au m�me moment.
		** Donc sur un port 8 bits on �crit un octet.
		*/
	int32 majSorties();
	
		/* Accesseurs
		** Permettent d'obtenir les valeurs des attributs priv�s de la classe
		** Dans ce mod�le seule l'image des donn�es en entr�e a un sens.
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
		** Permettent d'affecter une valeur aux attributs priv�s de la classe
		** Dans ce mod�le seule l'image des donn�es en sortie a un sens.
		*/
	void setVannePVCBase(bool etat);
	void setVannePVCBaseFD(bool etat);
	void setVannePlastifiant(bool etat);
	void setVanneLubrifiant(bool etat);
	void setVanneVidange(bool etat);
	void setMalaxeur(bool etat);
	void setEvacuation(bool etat);
	void setVoyantRouge(bool etat);
	
		/* R�cup�ration du texte correspondant au num�ro d'erreur retoun� par les fonctions DAQmx
		** On passe le num�ro d'erreur
		** On r�cup�re la cha�ne en string
		*/

	void lancerCycleFabrication(int masse_pvc_base, int masse_plastifiant, int masse_lubrifiant, int temps_malaxage, int temps_refroidissement);

	std::string texteErreur(int32 code);
};
#endif
