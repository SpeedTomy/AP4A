#include "Server.h"
#include <iostream>
#include <fstream>

// Constructeur
Server::Server() {

    // Initialisation des compteurs à zéro
    sensorCounts[0] = 0; // Temperature
    sensorCounts[1] = 0; // Humidity
    sensorCounts[2] = 0; // Light
}

// Destructeur
Server::~Server() {
    // Libérer la mémoire des capteurs
    for (Sensor* sensor : sensors) {
        delete sensor;
    }
}

// Ajouter un capteur à la liste
void Server::addSensor(Sensor& sensor) {
    sensors.push_back(&sensor);

    if (sensor.getType() == "Temperature") {
        sensorCounts[0]++;
    } else if (sensor.getType() == "Humidity") {
        sensorCounts[1]++;
    } else if (sensor.getType() == "Light") {
        sensorCounts[2]++;
    }
}

int Server::getSensorCount(const std::string& type) const {
    if (type == "Temperature") {
        return sensorCounts[0];
    } else if (type == "Humidity") {
        return sensorCounts[1];
    } else if (type == "Light") {
        return sensorCounts[2];
    }
    return 0; // Aucun capteur de ce type
}

// Afficher les données dans la console
void Server::consoleWrite(const std::string& data) {
    std::cout << data << std::endl;
}

// Écrire les données dans un fichier de log
void Server::fileWrite(const std::string& filename, const std::string& data) {
    std::ofstream logfile(filename, std::ios::app);  // Ouvrir le fichier en mode ajout
    if (logfile.is_open()) {
        logfile << data << std::endl;  // Écrire les données dans le fichier
        logfile.close();               // Fermer le fichier
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier " << filename << std::endl;
    }
}

// Retourner la liste des capteurs
const std::vector<Sensor*>& Server::getSensors() const {
    return sensors;
}

// Implémentation de la nouvelle méthode receiveData
// void Server::receiveData(const std::string& data) {
//     // Ajoute les données au journal interne
//     dataLog.push_back(data);

//     // Affiche les données dans la console
//     consoleWrite("Données reçues : " + data);

//     // Écrit les données dans le fichier de log
//     fileWrite("log_sensor.csv", data);
// }