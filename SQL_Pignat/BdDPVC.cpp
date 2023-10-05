#include "BdDPVC.h"
#include <stdexcept>
#include <iostream>

CBdDPVC::CBdDPVC() {

    driver = get_driver_instance();
    con = nullptr;
    stmt = nullptr;

}

bool CBdDPVC::connecter() {

    try {
        con = driver->connect("tcp://10.187.52.4:3306", "beaujardt", "beaujardt");
        con->setSchema("beaujardt_b");
        stmt = con->createStatement();
    }
    catch (sql::SQLException& e) {
        std::cerr << "Erreur lors de la connexion: " << e.what();
        return false;
    }

    return true;
}

bool CBdDPVC::connecter(std::string serveur, std::string login, std::string password, std::string baseDeDonnee) {

    try {
        con = driver->connect(serveur, login, password);
        con->setSchema(baseDeDonnee);
        stmt = con->createStatement();
    }
    catch (sql::SQLException& e) {
        std::cerr << "Erreur lors de la connexion: " << e.what();
        return false;
    }

    return true;
}

void CBdDPVC::deconnecter() {
    delete stmt;
    delete con;
    stmt = nullptr;
    con = nullptr;
}

bool CBdDPVC::estUnOperateurAutorise(CPersonnel user) {
   
    bool estOperateur = false;
    try {

        std::string requete = "SELECT COUNT(*) FROM personnel WHERE login = " + user.getLogin() + " AND password = " + user.getPassword() + " AND qualite = 'OPERATEUR'";
        sql::ResultSet* res = stmt->executeQuery(requete);
       
        if (res->next() && res->getInt(1) > 0)
            estOperateur = true;

        delete res;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Erreur SQL : " << e.what();
    }

    return estOperateur;
}

std::vector<std::string> CBdDPVC::getListeReferencesOF() {
    
    std::vector<std::string> references;

    try {

        sql::ResultSet* res = stmt->executeQuery("SELECT reference FROM ordrefabrication");
        while (res->next()) {
            references.push_back(res->getString("reference"));
        }

        delete res;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Erreur SQL : " << e.what();
    }
     
    return references;
}


CFormule CBdDPVC::makeFormule(int idF) {
    
    try {
        res = stmt->executeQuery("SELECT * FROM formule WHERE id_formule = " + std::to_string(idF));

        if (res->next())
        {
            float pvcBase = stof(res->getString("pvcBase"));
            float plastifiant = stof(res->getString("plastifiant"));
            float lubrifiant = stof(res->getString("lubrifiant"));


            std::cout << "% de pvc : " << pvcBase << " - quantit\202 : " << quantite * (pvcBase / 100.0) << endl;
            std::cout << "% de plastifiant : " << plastifiant << " - quantit\202 : " << quantite * (plastifiant / 100.0) << endl;
            std::cout << "% de lubrifiant : " << lubrifiant << " - quantit\202 : " << quantite * (lubrifiant / 100.0) << endl;
        }
    }
    catch (sql::SQLException& e) {
        std::cerr << "Erreur SQL : " << e.what();
    }

 


   /* CFormule formule();
    CFormule(Type type, double pvcBase, double plastifiant,
        double lubrifiant, unsigned short dureeMalaxage,
        unsigned short dureeRefroidissement); */

}

CPersonnel CBdDPVC::makePersonnel(int idP) {
   
}

int CBdDPVC::getIdFormule(CFormule formule) {
   
}

int CBdDPVC::getIdPersonnel(CPersonnel user) {
  
}

int CBdDPVC::getIdOF(COrdreFabrication of) {
   
}
