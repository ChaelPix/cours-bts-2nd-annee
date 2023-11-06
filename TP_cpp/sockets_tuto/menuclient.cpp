//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <iostream>
//#include <string>
//#include <vector>      
//#include <sstream>   
//#include <regex>   
//
//#include "TrameAnalyzer.h"
//
//using namespace std;
//
//typedef unsigned int uint;
//typedef unsigned short ushort;
//typedef unsigned char uchar;
//
//ushort NUM_PORT = 0;
//const ushort DIMMAX = 150; // Taille max des tableaux
//string IP_SERVEUR = "";
//
//std::string getTrameInfo(uint& ids_client, sockaddr_in& adr_serveur, bool temp, bool hum);
//
//std::vector<std::string> split(const std::string& s, char delimiter)
//{
//    std::vector<std::string> tokens;
//    std::string token;
//    std::istringstream tokenStream(s);
//    while (std::getline(tokenStream, token, delimiter))
//    {
//        tokens.push_back(token);
//    }
//    return tokens;
//}
//
//int main(int argc, char* argv[])
//{
//
//    if (argc < 3)
//    {
//        std::cout << "Erreur : Entrez IP (x.x.x.x) puis le Port !";
//        return -1;
//    }
//
//    /*---------IP Verif--------*/
//    std::string ip = argv[1];
//
//
//    IP_SERVEUR = argv[1];
//    std::regex regex("^((25[0-5]|2[0-4]\\d|1\\d{2}|[1-9]\\d?|0)\\.){3}(25[0-5]|2[0-4]\\d|1\\d{2}|[1-9]\\d?|0)$");
//    std::smatch regexSmatch;
//
//    if (std::regex_search(IP_SERVEUR, regexSmatch, regex)) {
//        std::cout << "IP OK : " << regexSmatch.str() << std::endl;
//    }
//    else {
//        std::cout << "Vérifiez votre adresse IP." << std::endl;
//        return -1;
//    }
//
//    /*---------Port Verif--------*/
//    try
//    {
//        NUM_PORT = std::stoi(argv[2]);
//    }
//    catch (const std::invalid_argument& e)
//    {
//        std::cout << "Erreur : Port doit etre un nombre entier";
//        return -1;
//    }
//
//    std::cout << "Adr serveur : " << IP_SERVEUR << " : " << NUM_PORT << std::endl;
//
//    // Particularités Windows
//    WORD nVersion = MAKEWORD(2, 2);
//    WSADATA donneeWS;
//
//    struct sockaddr_in adr_serveur; // @ internet du serveur
//
//    uint  ids_client;   // id du socket client                  
//    // tableau contenant les messages provenant du serveur  
//
//
//    // initialisation du winsock
//    WSAStartup(nVersion, &donneeWS);
//
//    cout << "--- DEBUT du prog" << endl << endl;
//
//    // Création du socket client
//    if ((ids_client = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
//    {
//        cout << "Echec creation Socket ! " << endl;
//        exit(1);
//    }
//
//    // Mise en place de l'@ inet et demande de connexion au serveur 
//    adr_serveur.sin_family = AF_INET;                  // Domaine d'@ 
//    adr_serveur.sin_port = htons(NUM_PORT);          // N° du port 
//    inet_pton(AF_INET, IP_SERVEUR.c_str(), &adr_serveur.sin_addr) <= 0;
//
//    uint n = 0, noctets;
//    char trame_lect[DIMMAX + 1];
//
//    if (connect(ids_client, (struct sockaddr*)&adr_serveur, sizeof(adr_serveur)) < 0)
//    {
//        cout << "Echec connexion ! " << endl;
//        exit(1);
//    }
//
//    std::string input = "";
//    bool enCours = true;
//
//    while (enCours)
//    {
//        std::cout << "Saisissez votre commande parmi TMP, HUM, ALL, BYE : ";
//        std::cin >> input;
//
//        send(ids_client, input.c_str(), input.size() + 1, 0);
//
//        noctets = recv(ids_client, trame_lect, DIMMAX, 0);
//        trame_lect[noctets] = '\0';
//
//        cout << "trame transmise par ce serveur: " << trame_lect << endl;
//        if (input == "BYE")
//        {
//            enCours = false;
//        }
//    }
//
//    // fermeture le socket ouvert
//    closesocket(ids_client);
//
//    // Fermeture de winsock
//    WSACleanup();
//
//
//
//
//    // Affichage des données reçues
//    //cout << "Longueur de la chaine recue = " << noctets << endl;
//    //cout << "Trame recue du serveur = " << trame_lect << endl;
//
//
//
//    //---- Traitement de la trame 
//
//    //----
//
//    cout << "--- FIN du prog" << endl;
//
//    cin.get();
//    return 0;
//}
//
