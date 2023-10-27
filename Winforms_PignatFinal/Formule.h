#ifndef _FORMULE_
#define _FORMULE_

// Pour uilisation dans un projet "managé"
//#include "stdafx.h"
#include <string>

class CFormule
{
public:
	// Pour limiter le choix du type (et les erreurs)
	enum Type {SOUPLE, RIGIDE};
	CFormule();
	CFormule(Type type, double pvcBase, double plastifiant,
				double lubrifiant, unsigned short dureeMalaxage,
				unsigned short dureeRefroidissement);
	
	void setType(Type type);
	void setPvcBase(double pvcBase);
	void setPlastifiant(double plastifiant);
	void setLubrifiant(double lubrifiant);
	void setDureeMalaxage(unsigned short dureeMalaxage);
	void setDureeRefroidissement(unsigned short dureeRefroidissement);

	std::string getType() const;
	double getPvcBase() const;
	double getPlastifiant() const;
	double getLubrifiant() const;
	unsigned short getDureeMalaxage() const;
	unsigned short getDureeRefroidissement() const;
	
	std::string toString() const;

private:
	std::string m_type;
	double m_pvcBase;
	double m_plastifiant;
	double m_lubrifiant;
	unsigned short m_dureeMalaxage;
	unsigned short m_dureeRefroidissement;
};

#endif