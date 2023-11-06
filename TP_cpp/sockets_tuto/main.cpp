#include <winsock2.h>
#include<ctime>
#include <sstream>
#include <iostream>
#include <string>
#include <chrono>
#include <cstring>
using namespace std;

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

const ushort PORT_NUM = 55555;

#include <random>
struct mesure {
    char date[26];
    float valTemp;
    float valHum;
};


void prendreMesure(mesure& m) {
    double valTemp = 0.0;
    double valHum = 0.0;

    // Tirage aléatoire de nombres
    std::random_device rd;
    std::mt19937 mt(rd()); // Mersenne Twister

    // tirage pour la valeur du capteur de température entre 15°C et 25°C, tirage d'un double
    std::uniform_real_distribution<double> dist(15.0, 25.0);
    valTemp = dist(mt);

    // tirage pour la valeur du capteur d'hygrométrie entre 10%RH et 90%RH, tirage d'un entier
    valHum = rand() % 80 + 10;

    // récupération de la date et l'heure courante
    time_t tempsCourant = time(nullptr); 
    struct tm timeinfo;
    localtime_s(&timeinfo, &tempsCourant);
    char buffer[26];
    asctime_s(buffer, sizeof(buffer), &timeinfo);
    std::string dateHeureMesure(buffer);

    // remplissage de la structure avec les valeurs précédentes
    strcpy_s(m.date, sizeof(m.date), buffer);
    m.valHum = valHum;
    m.valTemp = valTemp; 
}

int main(void)
{
    // Initialisation du générateur de nombres aléatoires
    srand(static_cast<unsigned int>(time(NULL)));

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

    mesure m;
    prendreMesure(m);

   if ((nb_car_emis = send(ids_connect, reinterpret_cast<char*>(&m), sizeof(m), 0)) == SOCKET_ERROR)
    {
        cout << "Echec transmission " << endl;
        exit(1);
    }

    cout << "nb car emis par ce serveur : " << nb_car_emis << endl;
    cout << "trame transmise par ce serveur: " << reinterpret_cast<char*>(&m) << endl;

    // fermeture des sockets ouverts
    closesocket(ids_ecoute);
    closesocket(ids_connect);

    // Fermeture de winsock
    WSACleanup();

    cout << "--- FIN du prog" << endl;
    cin.get();
    return 0;
}