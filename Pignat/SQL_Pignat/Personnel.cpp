#include "Personnel.h"

CPersonnel::CPersonnel()
	: m_login(""), m_password(""), m_qualite("INCONNU")
{
}

CPersonnel::CPersonnel(std::string login, std::string password, Qualite qualite) 
	: m_login(login), m_password(password), m_qualite(qualite == CPersonnel::Qualite::OPERATEUR ? "OPERATEUR" : "PREPARATEUR")
{
}


void CPersonnel::setLogin(std::string login)
{
	this->m_login = login;
}

void CPersonnel::setPassword(std::string password)
{
	this->m_password = password;
}

void CPersonnel::setQualite(Qualite qualite)
{
	qualite == Qualite::OPERATEUR ? this->m_qualite = "OPERATEUR" : this->m_qualite = "PREPARATEUR";
}

std::string CPersonnel::getLogin() const
{
	return m_login;
}

std::string CPersonnel::getPassword() const
{
	return m_password;
}

std::string CPersonnel::getQualite() const
{
	return m_qualite;
}

std::string CPersonnel::toString() const
{
	std::string s = "Login : " + m_login + " Mdp : " + m_password + " Qualite : " + m_qualite;

	return s;
}
