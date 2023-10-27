#ifndef PERSONNEL
#define PERSONNEL

// En cas d'utilisation dans un projet "managé"
//#include "stdafx.h"
#include <string>

class CPersonnel
{
public :
	// pour définir la qualité ;
	// ceci nous permet de limiter les erreurs ---> cf. Constructeurs
	enum class Qualite {OPERATEUR, PREPARATEUR, INCONNU};
	CPersonnel();
		// Constructeur avec initialisation des paramètres
		// le paramètre qualite ne peut prendre que 2 valeurs :
		// CPersonnel::OPERATEUR ou CPersonnel::PREPARATEUR
	CPersonnel(std::string login, std::string password, Qualite qualite);
	
	void setLogin(std::string login);
	void setPassword(std::string password);
	void setQualite(Qualite qualite);

	std::string getLogin() const;
	std::string getPassword() const;
	std::string getQualite() const;
	
	std::string toString() const;

private :
	std::string m_login;
	std::string m_password;
	std::string m_qualite;
};

#endif