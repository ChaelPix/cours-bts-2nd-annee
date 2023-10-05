#include "OrdreFabrication.h"


COrdreFabrication::COrdreFabrication()
    : m_reference(""), m_formule(), m_quantite(0.0), m_etat('X'), m_heureFin(""), m_preparateur() {}

COrdreFabrication::COrdreFabrication(std::string reference, CFormule formule, double quantite,
    Etat etat, std::string heureFin, CPersonnel preparateur)
    : m_reference(reference), m_formule(formule), m_quantite(quantite), m_etat(toChar(etat)), m_heureFin(heureFin), m_preparateur(preparateur) {}

void COrdreFabrication::setReference(std::string reference) {
    m_reference = reference;
}

void COrdreFabrication::setFormule(CFormule formule) {
    m_formule = formule;
}

void COrdreFabrication::setQuantite(double quantite) {
    m_quantite = quantite;
}

void COrdreFabrication::setEtat(Etat etat) {
    m_etat = toChar(etat);
}

void COrdreFabrication::setHeureFin(std::string heureFin) {
    m_heureFin = heureFin;
}

void COrdreFabrication::setPreparateur(CPersonnel preparateur) {
    m_preparateur = preparateur;
}

std::string COrdreFabrication::getReference() const {
    return m_reference;
}

CFormule COrdreFabrication::getFormule() const {
    return m_formule;
}

double COrdreFabrication::getQuantite() const {
    return m_quantite;
}

char COrdreFabrication::getEtat() const {
    return m_etat;
}

std::string COrdreFabrication::getHeureFin() const {
    return m_heureFin;
}

CPersonnel COrdreFabrication::getPreparateur() const {
    return m_preparateur;
}

std::string COrdreFabrication::toString() const {
    return "Reference: " + m_reference +
        "\nFormule: " + m_formule.toString() +
        "\nQuantite: " + std::to_string(m_quantite) +
        "\nEtat: " + m_etat +
        "\nHeure de fin: " + m_heureFin +
        "\nPreparateur: " + m_preparateur.toString();
}

char COrdreFabrication::toChar(Etat etat)
{
    switch (etat) {
    case X: return 'X';
    case E: return 'E';
    case T: return 'T';
    default: return 'X';  
    }
}

