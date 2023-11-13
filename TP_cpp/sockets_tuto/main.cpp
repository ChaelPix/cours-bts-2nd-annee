#include <winsock2.h>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
using namespace std;

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

const ushort PORT_NUM = 55555;
int nbServices = 5;

std::vector<uint> clientIds;
int nbClients = 0;

queue<uint> clientQueue;

#include <random>
struct mesure {
    std::string date;
    float valTemp;
    float valHum;

    std::string toString() {
        std::string s = date + "/" + std::to_string(valTemp) + "/" + std::to_string(valHum);
        return s;
    }
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
    m.date = dateHeureMesure;
    m.valHum = valHum;
    m.valTemp = valTemp; 
}

void traiterClient(uint ids_connect, int idThread)
{
    mesure m;
    prendreMesure(m);
    std::string msg = m.toString();

    if (send(ids_connect, msg.c_str(), msg.size() + 1, 0) == SOCKET_ERROR) {
        cout << "Echec transmission " << endl;
    }
    else {
        cout << "Thread #" << std::this_thread::get_id() << " Trame transmise par ce serveur : " << msg << endl;
    }

    chrono::seconds dt1(5);
    this_thread::sleep_for(dt1);
    std::string msg2 = "\nFin de la connexion.";

    if (send(ids_connect, msg2.c_str(), msg2.size() + 1, 0) == SOCKET_ERROR) {
        cout << "Echec transmission " << endl;
    }
    else {
        cout << "Thread #" << std::this_thread::get_id() << " Trame transmise par ce serveur : " << msg2 << endl;
    }

    closesocket(ids_connect);
    nbServices--;
}


void ClientRoom(uint ids_connect)
{
     clientQueue.push(ids_connect);
  
    // Attente d'un match
    while (clientQueue.size() < 2) {
        this_thread::sleep_for(chrono::seconds(1));
    }

    // Matchmaking
    uint pairedClient;
    pairedClient = clientQueue.front();
    clientQueue.pop(); 

    if (pairedClient != ids_connect) {
        // Envoi d'une notification de matchmaking aux deux clients
        string msg = "Copain trouvé!\n" + std::to_string(pairedClient);
        string msg2 = "Copain trouvé!\n" + std::to_string(ids_connect);
        send(ids_connect, msg.c_str(), msg.size() + 1, 0);
        send(pairedClient, msg2.c_str(), msg2.size() + 1, 0);

        char buffer[1024];
        int receivedBytes;
        while (true) {
            memset(buffer, 0, sizeof(buffer)); // Nettoyage du buffer

            receivedBytes = recv(ids_connect, buffer, sizeof(buffer), 0);
            if (receivedBytes <= 0) break; // Client déconnecté ou erreur

            std::string msg = '\n' + buffer;
            send(pairedClient, msg.c_str(), msg.size() + 1, 0); // Envoi du message au client apparié

            // Répéter pour l'autre client
            memset(buffer, 0, sizeof(buffer));
            receivedBytes = recv(pairedClient, buffer, sizeof(buffer), 0);
            if (receivedBytes <= 0) break; // Client déconnecté ou erreur

            msg = '\n' + buffer;
            std::cout << msg;
            send(ids_connect, msg.c_str(), msg.size() + 1, 0); // Envoi du message au premier client
        }
    }

    closesocket(ids_connect);
    closesocket(pairedClient);
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

    vector<thread> clientThreads;

    while (nbServices > 0)
    {
        // Acceptation d'une connexion cliente, création d'un nouveau socket qui 
        // sera utilisé pour l'émission et la réception des caractères 
        // @ inet du clietnt est récupérée
        addr_len = sizeof(adr_client);

        ids_connect = accept(ids_ecoute, (struct sockaddr*)&adr_client, &addr_len);
        thread clientThread(ClientRoom, ids_connect);
        clientThread.detach();
        //clientThreads.emplace_back(traiterClient, ids_connect, clientThreads.size());
        //clientThreads.emplace_back(ClientRoom, ids_connect);
    }

    closesocket(ids_ecoute);

    // Fermeture de winsock
    WSACleanup();

    cout << "--- FIN du prog" << endl;
    cin.get();
    return 0;
}