#include <iostream>

// Les includes strictement nécessaire pour cet exemple
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <vector>
using namespace std;

struct Login
{
    string name;
    string password;
    int idPersonnel;
};

//Un programme qui, pour un ordre de fabrication, positionne l'indicateur d'état de "en cours" à "terminé" et met à jour le champ "heurefin" avec l'heure et la date du moment d'exécution du programme.
int q3_6()
{
    vector<int> orders;
    sql::PreparedStatement* pstmt;

    Login myLogin;
    std::cout << "Login : ";
    std::cin >> myLogin.name;
    std::cout << "Password : ";
    std::cin >> myLogin.password;

    cout << endl;

    try {
        // Les variables nécessaires à notre programme
        sql::Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        //Créer une connexion à la BDD
        driver = get_driver_instance();
        con = driver->connect("tcp://10.187.52.4:3306", "beaujardt", "beaujardt");
        con->setSchema("beaujardt_b");
        stmt = con->createStatement();

        //*********Login
        pstmt = con->prepareStatement("SELECT * FROM personnel WHERE login = ? AND password = ?");
        pstmt->setString(1, myLogin.name);
        pstmt->setString(2, myLogin.password);
        res = pstmt->executeQuery();

        if (res->next())
        {
            cout << "Vous etes : " << res->getString("qualite") << " ID : " << res->getString("id_Personnel") << endl;
            myLogin.idPersonnel = stoi(res->getString("id_Personnel"));
        }
        else
        {
            cout << "Login échoué." << endl;
            return -1;
        }

        //*********Ordres non traites
        res = stmt->executeQuery("SELECT id_OrdreFabrication, reference FROM ordrefabrication WHERE etat = 'E'");

        cout << "\t... Ordres Fabrications en cours : " << endl << endl;
        while (res->next()) {
            cout << "id :  " << res->getString("id_OrdreFabrication") << " > r\202ference : " << res->getString("reference") << endl;
            orders.push_back(stoi(res->getString("id_OrdreFabrication")));
        }
        if (orders.size() == 0)
        {
            std::cout << "Aucun ordre en cours";
            return -1;
        }

        //*********Maj ordre
        std::cout << std::endl << "Quel ordre de fabrication terminer ?" << std::endl;
        int id;
        std::cin >> id;

        bool isIdOk = false;
        for (int i = 0; i < orders.size(); i++)
        {
            if (id == orders.at(i))
                isIdOk = true;
        }

        if (!isIdOk)
        {
            std::cout << "Cet id n'est pas associ\202 a un ordre en cours ";
            return -1;
        }

        stmt->executeUpdate("UPDATE ordrefabrication SET etat = 'T', id_Personnel = " + std::to_string(myLogin.idPersonnel) + ", heurefin = NOW() WHERE id_OrdreFabrication = " + std::to_string(id));
        std::cout << "Ordre termin\202 !";


        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        // Gestion des execeptions pour déboggage
        cout << "# ERR: " << e.what();
        cout << " (code erreur MySQL: " << e.getErrorCode();
        cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
    }
    cout << endl;

    int pause;
    std::cin >> pause;
    // on sort en indiquant que tout c'est bien passé
    return EXIT_SUCCESS;
}

//Un programme qui, pour un ordre de fabrication, positionne l'indicateur d'état de "non traité" à "en cours" et met à jour le champ "id_Personnel" avec un identificateur valide d'opérateur
int q3_5()
{
    vector<int> orders;
    sql::PreparedStatement* pstmt;

    Login myLogin;
    std::cout << "Login : ";
    std::cin >> myLogin.name;
    std::cout << "Password : ";
    std::cin >> myLogin.password;

    cout << endl;

    try {
        // Les variables nécessaires à notre programme
        sql::Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        //Créer une connexion à la BDD
        driver = get_driver_instance();
        con = driver->connect("tcp://10.187.52.4:3306", "beaujardt", "beaujardt");
        con->setSchema("beaujardt_b");
        stmt = con->createStatement();

        //*********Login
        pstmt = con->prepareStatement("SELECT * FROM personnel WHERE login = ? AND password = ?");
        pstmt->setString(1, myLogin.name);
        pstmt->setString(2, myLogin.password);
        res = pstmt->executeQuery();

        if (res->next())
        {
            cout << "Vous etes : " << res->getString("qualite") << " ID : " << res->getString("id_Personnel") << endl;
            myLogin.idPersonnel = stoi(res->getString("id_Personnel"));
        }
        else
        {
            cout << "Login échoué." << endl;
            return -1;
        }

        //*********Ordres non traites
        res = stmt->executeQuery("SELECT id_OrdreFabrication, reference FROM ordrefabrication WHERE etat = 'X'");

        cout << "\t... Ordres Fabrications non trait\202s : " << endl << endl;
        while (res->next()) {
            cout << "id :  " << res->getString("id_OrdreFabrication") << " > r\202ference : " << res->getString("reference") << endl;
            orders.push_back(stoi(res->getString("id_OrdreFabrication")));
        }
        if (orders.size() == 0)
        {
            std::cout << "Tous les ordres sont trait\202s";
            return -1;
        }

        //*********Maj ordre
        std::cout << std::endl << "Quel ordre de fabrication lancer ?" << std::endl;
        int id;
        std::cin >> id;

        bool isIdOk = false;
        for (int i = 0; i < orders.size(); i++)
        {
            if (id == orders.at(i))
                isIdOk = true;
        }

        if(!isIdOk)
        {
            std::cout << "Cet id n'est pas associ\202 a un ordre non trait\202 ";
            return -1;
        }

        stmt->executeUpdate("UPDATE ordrefabrication SET etat = 'E', id_Personnel = " + std::to_string(myLogin.idPersonnel) + " WHERE id_OrdreFabrication = " + std::to_string(id));
        std::cout << "Ordre mis en cours !";


        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        // Gestion des execeptions pour déboggage
        cout << "# ERR: " << e.what();
        cout << " (code erreur MySQL: " << e.getErrorCode();
        cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
    }
    cout << endl;

    int pause;
    std::cin >> pause;
    // on sort en indiquant que tout c'est bien passé
    return EXIT_SUCCESS;
}

//Un programme qui permet de choisir un ordre de fabrication non traité et qui calcule et affiche les quantités de produits nécessaires à cette fabrication
int q3_4()
{
    cout << endl;
    try {
        // Les variables nécessaires à notre programme
        sql::Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        // Etape 1 : créer une connexion à la BDD
        driver = get_driver_instance();
        // on note les paramètres classiques: adresse ip du serveur et port, login, mot de passe
        con = driver->connect("tcp://10.187.52.4:3306", "beaujardt", "beaujardt");

        // Etape 2 : connexion à la base choisie, ici olivier_db
        con->setSchema("beaujardt_b");

        // Etape 3 : création d'un objet qui permet d'effectuer des requêtes sur la base
        stmt = con->createStatement();

        // Etape 4 : exécution d'une requete : ici on sélectionne tous les enregistrements
        res = stmt->executeQuery("SELECT id_OrdreFabrication, reference FROM ordrefabrication WHERE etat = 'X'");

        // Etape 5 : exploitation du résultat de la requête
        cout << "\t... MySQL a repondu: Ordres Fabrications non trait\202s : " << endl << endl;
        while (res->next()) {
            cout << "id :  " << res->getString("id_OrdreFabrication") << " > r\202ference : " << res->getString("reference") << endl;
        }
        std::cout << std::endl << "Traiter les quantit\202s de produits de quel ordre ?" << std::endl;
        int id;
        std::cin >> id;

        res = stmt->executeQuery("SELECT * FROM ordrefabrication WHERE etat = 'X' AND id_OrdreFabrication = " + std::to_string(id));
        if (res->next())
        {
            float quantite = stof(res->getString("quantite"));
            cout << std::endl << "L'ordre a une quantit\202 de :  " << quantite;
            cout << std::endl << "L'id de formule est : " << res->getString("id_Formule") << std::endl;


            res = stmt->executeQuery("SELECT * FROM formule WHERE id_formule = " + res->getString("id_Formule"));
            if (res->next())
            {
                float pvcBase = stof(res->getString("pvcBase"));
                float plastifiant = stof(res->getString("plastifiant"));
                float lubrifiant = stof(res->getString("lubrifiant"));


                std::cout << "% de pvc : " << pvcBase << " - quantit\202 : " << quantite * (pvcBase / 100.0) << endl;
                std::cout << "% de plastifiant : " << plastifiant << " - quantit\202 : " << quantite * (plastifiant / 100.0) << endl;
                std::cout << "% de lubrifiant : " << lubrifiant << " - quantit\202 : " << quantite * (lubrifiant / 100.0) << endl;
            }
            else
                std::cout << "Pas de formule associ\202e";
        }
        else
            std::cout << "Cet id n'est pas associ\202 a un ordre non trait\202 ";


        // On nettoie tout avant de sortir : effacement des pointeurs
        // le pointeur sur le Driver sera effacé tout seul
        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        // Gestion des execeptions pour déboggage
        cout << "# ERR: " << e.what();
        cout << " (code erreur MySQL: " << e.getErrorCode();
        cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
    }
    cout << endl;

    int pause;
    std::cin >> pause;
    // on sort en indiquant que tout c'est bien passé
    return EXIT_SUCCESS;
}

//Un programme qui affiche la liste des ordres de fabrication non traités
int q3_3()
{
    cout << endl;
    cout << "Premier test du connecteur C++ Mysql" << endl;
    try {
        // Les variables nécessaires à notre programme
        sql::Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        // Etape 1 : créer une connexion à la BDD
        driver = get_driver_instance();
        // on note les paramètres classiques: adresse ip du serveur et port, login, mot de passe
        con = driver->connect("tcp://10.187.52.4:3306", "beaujardt", "beaujardt");

        // Etape 2 : connexion à la base choisie, ici olivier_db
        con->setSchema("beaujardt_b");

        // Etape 3 : création d'un objet qui permet d'effectuer des requêtes sur la base
        stmt = con->createStatement();

        // Etape 4 : exécution d'une requete : ici on sélectionne tous les enregistrements
        res = stmt->executeQuery("SELECT id_OrdreFabrication, reference FROM ordrefabrication WHERE etat = 'X'");

        // Etape 5 : exploitation du résultat de la requête
        cout << "\t... MySQL a repondu: Ordres Fabrications non trait\202s : " << endl;
        while (res->next()) {  
            cout << "id :  "<< res->getString("id_OrdreFabrication") << " > r\202ference : " << res->getString("reference") <<  endl;
        }

        // On nettoie tout avant de sortir : effacement des pointeurs
        // le pointeur sur le Driver sera effacé tout seul
        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        // Gestion des execeptions pour déboggage
        cout << "# ERR: " << e.what();
        cout << " (code erreur MySQL: " << e.getErrorCode();
        cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
    }
    cout << endl;

    int pause;
    std::cin >> pause;
    // on sort en indiquant que tout c'est bien passé
    return EXIT_SUCCESS;
}

//Un programme qui indique si la personne qui s'identifie (login, mot de passe) est un opérateur
int q3_2()
{
    sql::PreparedStatement* pstmt;

    Login myLogin;
    std::cout << "Login : ";
    std::cin >> myLogin.name;
    std::cout << "Password : ";
    std::cin >> myLogin.password;

    cout << endl;

    try {
        // Les variables nécessaires à notre programme
        sql::Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        // Etape 1 : créer une connexion à la BDD
        driver = get_driver_instance();
        // on note les paramètres classiques: adresse ip du serveur et port, login, mot de passe
        con = driver->connect("tcp://10.187.52.4:3306", "beaujardt", "beaujardt");

        // Etape 2 : connexion à la base choisie, ici olivier_db
        con->setSchema("beaujardt_b");

        // Etape 3 : création d'un objet qui permet d'effectuer des requêtes sur la base
        stmt = con->createStatement();

        // Etape 4 : exécution d'une requete : ici on sélectionne tous les enregistrements
        //res = stmt->executeQuery("SELECT * FROM personnel WHERE login = '" + myLogin.name + "' AND password ='" + myLogin.password + "'");
        pstmt = con->prepareStatement("SELECT * FROM personnel WHERE login = ? AND password = ?");
        pstmt->setString(1, myLogin.name);
        pstmt->setString(2, myLogin.password);

        res = pstmt->executeQuery();

        // Etape 5 : exploitation du résultat de la requête
        if (res->next()) 
            cout << "Vous etes : " << res->getString("qualite") << endl;
        else 
            cout << "Login échoué." << endl;

        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        // Gestion des execeptions pour déboggage
        cout << "# ERR: " << e.what();
        cout << " (code erreur MySQL: " << e.getErrorCode();
        cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
    }
    cout << endl;

    int pause;
    std::cin >> pause;
    // on sort en indiquant que tout c'est bien passé
    return EXIT_SUCCESS;
}

//Un programme qui affiche la liste des opérateurs (login et mot de passe) à partir de la table Personnel
int q3_1()
{
    cout << endl;
    cout << "Premier test du connecteur C++ Mysql" << endl;
    try {
        // Les variables nécessaires à notre programme
        sql::Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        // Etape 1 : créer une connexion à la BDD
        driver = get_driver_instance();
        // on note les paramètres classiques: adresse ip du serveur et port, login, mot de passe
        con = driver->connect("tcp://10.187.52.4:3306", "beaujardt", "beaujardt");

        // Etape 2 : connexion à la base choisie, ici olivier_db
        con->setSchema("beaujardt_b");

        // Etape 3 : création d'un objet qui permet d'effectuer des requêtes sur la base
        stmt = con->createStatement();

        // Etape 4 : exécution d'une requete : ici on sélectionne tous les enregistrements
        res = stmt->executeQuery("SELECT * FROM personnel WHERE qualite = 'OPERATEUR");

        // Etape 5 : exploitation du résultat de la requête
        while (res->next()) {
            cout << "\t... MySQL a repondu: Liste des op\202rateurs : ";
            // Acces par non du champ de la table : ici le champ 'id' que l'on recupère au format string
            cout << res->getString("id_Personnel") << endl;
            cout << "\t... MySQL la suite : ";
            // Acces à la donnée par son numéro de colonne, 1 étant le premier (ici 'id'),
            cout << res->getString(2) << " : " << res->getString(3) << endl;
        }

        // On nettoie tout avant de sortir : effacement des pointeurs
        // le pointeur sur le Driver sera effacé tout seul
        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        // Gestion des execeptions pour déboggage
        cout << "# ERR: " << e.what();
        cout << " (code erreur MySQL: " << e.getErrorCode();
        cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
    }
    cout << endl;

    int pause;
    std::cin >> pause;
    // on sort en indiquant que tout c'est bien passé
    return EXIT_SUCCESS;
}

int main()
{
    bool isRunning = true;
    int choice;

    while (isRunning)
    {
        system("cls");
        std::cout << "\t.....:Choisir Exo:....." << std::endl << std::endl;
        
        std::cout << "[1] Q3.1 (Liste op\202rateurs de la table Personnel)" << std::endl;
        std::cout << "[2] Q3.2 (Identification d'un Op\202rateur)" << std::endl;
        std::cout << "[3] Q3.3 (Liste des ordres de fabrication non trait\202s)" << std::endl;
        std::cout << "[4] Q3.4 (Choisir un of non trait\202 et calcule quantit\202s)" << std::endl;
        std::cout << "[5] Q3.5 (Ordre de 'X' > 'E' et remplace id_Personnel)" << std::endl;
        std::cout << "[6] Q3.6 (Ordre de 'E' > 'T', remplace id_Personnel et Heure de fin > NOW())" << std::endl;
        std::cout << "[0] Quitter" << std::endl;

        std::cin >> choice;

        system("cls");
        std::cout << "Choix de l'exercice : " + (choice) << std::endl << std::endl << std::endl;
        switch (choice)
        {
        case '1': q3_1();  break;
        case '2': q3_2();  break;
        case '3': q3_3();  break;
        case '4': q3_4();  break;
        case '5': q3_5();  break;
        case '6': q3_6();  break;
           

        default:
            isRunning = false;
        }
    }
   
   

    return 0;
}


