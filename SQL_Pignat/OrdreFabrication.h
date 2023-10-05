#ifndef _ORDREFAB_
#define _ORDREFAB_

// Pour utilisation dans un projet "managé"
//#include "stdafx.h"

// Eventuellement modifier le chemin
#include "Formule.h"
#include "Personnel.h"

#include <string>

class COrdreFabrication
{
public:
	//Pour éviter toute erreur !
	enum Etat {X, E, T}; // Non traite ; En cours; Terminé
	COrdreFabrication();
	COrdreFabrication(std::string reference, CFormule formule, double quantite,
						Etat etat, std::string heureFin, CPersonnel preparateur );

	void setReference(std::string reference);
	void setFormule(CFormule formule);
	void setQuantite(double quantite);
	void setEtat(Etat etat);
	void setHeureFin(std::string heureFin);
	void setPreparateur(CPersonnel preparateur);

	std::string getReference() const;
	CFormule getFormule() const;
	double getQuantite() const;
	char getEtat() const;
	std::string getHeureFin() const;
	CPersonnel getPreparateur() const;
	
	std::string toString() const;

private :
	std::string m_reference;
	CFormule m_formule;
	double m_quantite;
	char m_etat;
	std::string m_heureFin;
	CPersonnel m_preparateur;

	char toChar(Etat etat) const;
};
 
#endif