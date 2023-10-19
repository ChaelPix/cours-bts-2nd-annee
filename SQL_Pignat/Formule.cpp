#include "Formule.h"

CFormule::CFormule()
    : m_type("SOUPLE"), m_pvcBase(0.0), m_plastifiant(0.0),
    m_lubrifiant(0.0), m_dureeMalaxage(0), m_dureeRefroidissement(0) {}

CFormule::CFormule(Type type, double pvcBase, double plastifiant,
    double lubrifiant, unsigned short dureeMalaxage,
    unsigned short dureeRefroidissement)
    : m_type(type == CFormule::Type::SOUPLE ? "SOUPLE" : "RIGIDE"), m_pvcBase(pvcBase),
    m_plastifiant(plastifiant), m_lubrifiant(lubrifiant),
    m_dureeMalaxage(dureeMalaxage),
    m_dureeRefroidissement(dureeRefroidissement) {}


#pragma region Set/Get
void CFormule::setType(Type type) {
    m_type = (type == CFormule::Type::SOUPLE ? "SOUPLE" : "RIGIDE");
}

void CFormule::setPvcBase(double pvcBase) {
    m_pvcBase = pvcBase;
}

void CFormule::setPlastifiant(double plastifiant) {
    m_plastifiant = plastifiant;
}

void CFormule::setLubrifiant(double lubrifiant) {
    m_lubrifiant = lubrifiant;
}

void CFormule::setDureeMalaxage(unsigned short dureeMalaxage) {
    m_dureeMalaxage = dureeMalaxage;
}

void CFormule::setDureeRefroidissement(unsigned short dureeRefroidissement) {
    m_dureeRefroidissement = dureeRefroidissement;
}

std::string CFormule::getType() const {
    return m_type;
}

double CFormule::getPvcBase() const {
    return m_pvcBase;
}

double CFormule::getPlastifiant() const {
    return m_plastifiant;
}

double CFormule::getLubrifiant() const {
    return m_lubrifiant;
}

unsigned short CFormule::getDureeMalaxage() const {
    return m_dureeMalaxage;
}

unsigned short CFormule::getDureeRefroidissement() const {
    return m_dureeRefroidissement;
}
#pragma endregion

std::string CFormule::toString() const {
    return "Type: " + m_type +
        "\nPVC Base: " + std::to_string(m_pvcBase) +
        "\nPlastifiant: " + std::to_string(m_plastifiant) +
        "\nLubrifiant: " + std::to_string(m_lubrifiant) +
        "\nDuree Malaxage: " + std::to_string(m_dureeMalaxage) +
        "\nDuree Refroidissement: " + std::to_string(m_dureeRefroidissement);
}
