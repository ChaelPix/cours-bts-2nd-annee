#include <winsock2.h>
#include<ctime>
#include <sstream>
#include <iostream>
#include <string>
#include <chrono>
using namespace std;

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

const ushort PORT_NUM = 55555;

int main(void)
{
    WORD nVersion = MAKEWORD(2, 2);
    WSADATA donneeWS;

    struct sockaddr_in   adr_serveur;       // @ internet du serveur
    struct sockaddr_in   adr_client;        // @ internet du client

    uint ids_ecoute;        // id du socket d'écoute du serveur
    uint ids_connect;       // id du socket de connection
    uint nb_car_emis;       // nb car émis par send

    int addr_len;          // taille de l'@ internet 

    // initialisation du winsock
    WSAStartup(nVersion, &donneeWS);

    cout << "--- DEBUT du prog " << endl;

    // Création du socket d'écoute
    if ((ids_ecoute = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        cout << "Echec creation Socket ! " << endl;
        exit(1);
    }

    // RAZ de la structure contenant @ inet serveur
    memset(&adr_serveur, 0, sizeof(adr_serveur));
    // Mise en forme de l'@ du socket d'écoute et attachement du socket
    adr_serveur.sin_family = AF_INET;            // Domain d'@ 
    adr_serveur.sin_port = htons(PORT_NUM);    // N° du port 
    adr_serveur.sin_addr.s_addr = htonl(INADDR_ANY);  // n'importe quel
    // interface réseau

    if (bind(ids_ecoute, (struct sockaddr*)&adr_serveur,
        sizeof(adr_serveur)) == SOCKET_ERROR)
    {
        cout << "Echec Attachement Socket ! " << endl;
        exit(1);
    }

    // Mise à disposition du socket (service) (1: une connection au max)
    if (listen(ids_ecoute, 1) == SOCKET_ERROR)
    {
        cout << "Echec Lecture ! " << endl;
        exit(1);
    }

    // Acceptation d'une connexion cliente, création d'un nouveau socket qui 
    // sera utilisé pour l'émission et la réception des caractères 
    // @ inet du clietnt est récupérée
    addr_len = sizeof(adr_client);
    ids_connect = accept(ids_ecoute, (struct sockaddr*)&adr_client, &addr_len);


    time_t tempsCourant = time(nullptr); // obtenir l'heure actuelle
    struct tm timeinfo; 
    localtime_s(&timeinfo, &tempsCourant);
    char buffer[26]; 
    asctime_s(buffer, sizeof(buffer), &timeinfo);

    std::string message(buffer); 

    if ((nb_car_emis = send(ids_connect, message.c_str(),
        message.size() + 1, 0)) == SOCKET_ERROR)
    {
        cout << "Echec transmission " << endl;
        exit(1);
    }
    cout << "nb car emis par ce serveur : " << nb_car_emis << endl;
    cout << "trame transmise par ce serveur: " << message << endl;

    // fermeture des sockets ouverts
    closesocket(ids_ecoute);
    closesocket(ids_connect);

    // Fermeture de winsock
    WSACleanup();

    cout << "--- FIN du prog" << endl;
    cin.get();
    return 0;
}