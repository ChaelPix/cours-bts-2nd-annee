// Exemple d'utilisation de la bibliothèque NI DAQ
// BTS SNIR
#include <iostream> // pour cin, cout
#include <Windows.h> // pour la fonction Sleep()
// prototypes des fonctions DAQmx, ce fichier doit être placé dans le répertoire de votre projet
#include "NIDAQmx.h"
using namespace std;
// Fonction principale
int main(void)
{
	// Le type TaskHandle est déclaré dans le fichier NIDAQmx.h
	TaskHandle tacheLectureDI0;
	// Le code de retour des fonctions sera stocké dans la variable erreur
	int32 erreur = 0;
	// Cette variable stockera le résultat de la lecture analogique
	uInt32 valDI0 = 0;
	cout << "..:: Debut programme ::.." << endl;
	// Création d'une nouvelle tâche, passage de l'identificateur de tache par adresse

	TaskHandle ecritureDO;

	erreur = DAQmxCreateTask("", &ecritureDO);
	if (erreur < 0) {
		cout << "Erreur lors de la création de la tache..." << endl;
	}
	else cout << "Creation de tache : ok" << endl;

	erreur = DAQmxCreateDOChan(ecritureDO, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
	if (erreur < 0) {
		cout << "Erreur de création de la voie digitale en sortie..." << endl;
	}
	else cout << "Creation du chan : ok" << endl;

	erreur = DAQmxStartTask(ecritureDO);
	if (erreur < 0) {
		cout << "Erreur au demarrage de la tache..." << endl;
		return (-1);
	}
	else cout << "Lancement de tache : ok" << endl;

	uInt32 valDO = 00;

	erreur = DAQmxWriteDigitalScalarU32(ecritureDO, false, 0, valDO, NULL);
	if (erreur < 0) {
		cout << "Erreur d'écriture de l'entrée..." << endl;
		return (-1);
	}
	else cout << "Valeur écrite : " << erreur << endl;

	//// Arrêt de la tache d'ecriture
	//erreur = DAQmxStopTask(ecritureDO);
	//if (erreur < 0) {
	//	cout << "Erreur lors de l'arret de la tache..." << endl;
	//	return (-1);
	//}
	//else cout << "Arret de la tache : ok" << endl;

	//// Effacement de la tache d'ecriture
	//erreur = DAQmxClearTask(ecritureDO);
	//if (erreur < 0) {
	//	cout << "Erreur lors de la suppression de la tache..." << endl;
	//	return (-1);
	//}




	//

	//erreur = DAQmxCreateTask("", &tacheLectureDI0); //on donne l'adresse de la variable car la fonction utilise un pointeur pour permettre à toutes les autres fonctions d'être associées à cette tache

	//// Si erreur est négatif, il y a eu un problème...
	//if (erreur < 0) {
	//	// On informe l'utilisateur...
	//	cout << "Erreur creation de la tache..." << endl;
	//	// et on quitte l'application avec un code négatif pour indiquer une erreur
	//	return (-1);
	//}
	//else cout << "Creation de tache : ok" << endl;

	//erreur = DAQmxCreateDIChan(tacheLectureDI0, "Dev3/port0", "", DAQmx_Val_ChanForAllLines);
	//if (erreur < 0) {
	//	cout << "Erreur de creation de la voie digitale en entree..." << endl;
	//	return (-1);

	//}
	//else cout << "Creation de chan : ok" << endl;

	//// Démarrage de la tache
	//erreur = DAQmxStartTask(tacheLectureDI0);
	//if (erreur < 0) {
	//	cout << "Erreur au demarrage de la tache..." << endl;
	//	return (-1);
	//}
	//else cout << "Lancement de tache : ok" << endl;

	//erreur = DAQmxReadDigitalScalarU32(tacheLectureDI0, 0, &valDI0, NULL); //à changer/copier pour l'entrée numérique
	//if (erreur < 0) {
	//	cout << "Erreur de lecture de l'entrée..." << endl;
	//	return (-1);
	//}
	//
	//// Affichage de la valeur digitale lue
	//cout << "Valeur lue : " << valDI0 << endl;
	//// Arrêt de la tache de lecture
	//erreur = DAQmxStopTask(tacheLectureDI0);
	//if (erreur < 0) {
	//	cout << "Erreur lors de l'arret de la tache..." << endl;
	//	return (-1);
	//}
	//else cout << "Arret de la tache : ok" << endl;

	//// Effacement de la tache de lecture
	//erreur = DAQmxClearTask(tacheLectureDI0);
	//if (erreur < 0) {
	//	cout << "Erreur lors de la suppression de la tache..." << endl;
	//	return (-1);
	//}

	//// Fin du programme et sortie sans erreur, on retourne 0
	//cout << "..:: Fin programme ::.." << endl;
	//return 0;

}