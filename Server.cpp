// Server.cpp
#include "Server.h"
#include <iostream>
#include <fstream>
#include <sstream>  // Pour convertir ID en string
#include <iomanip>
#include <ctime>
#include <filesystem>  // C++17 pour vérifier l'existence du fichier

// Constructeur
Server::Server() {
    sensorCounts[0] = 0;  // Temperature
    sensorCounts[1] = 0;  // Humidity
    sensorCounts[2] = 0;  // Light
    sensorCounts[3] = 0;  // Sound
}

// Destructeur
Server::~Server() {
    // Libérer la mémoire des capteurs
    for (Sensor* sensor : sensors) {
        delete sensor;
    }
}

// Ajouter un capteur au serveur
void Server::addSensor(Sensor& sensor) {

    sensors.push_back(&sensor);

    // Mise à jour des compteurs de capteurs par type
    if (sensor.getType() == "Temperature") {
        sensorCounts[0]++;
    } else if (sensor.getType() == "Humidity") {
        sensorCounts[1]++;
    } else if (sensor.getType() == "Light") {
        sensorCounts[2]++;
    } else if (sensor.getType() == "Sound") {
        sensorCounts[3]++;
    }

}

// Afficher des données dans la console
void Server::consoleWrite(const std::string& data) {
    std::cout << data << std::endl;
}

// Créer un fichier de log spécifique au capteur avec le format ID, Type, valeur, heure, date
void Server::fileWrite(const Sensor& sensor, const std::string& data) {
   
    // Créer un nom de fichier basé sur l'ID du capteur
    std::ostringstream filename;
    filename << "sensor_" << sensor.getType() << ".csv";  // Exemple: sensor_1.log

    // Récupérer l'heure actuelle pour l'ajouter au log
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    // Formatter l'heure (HH:MM:SS) et la date (YYYY-MM-DD)
    std::ostringstream timeStream, dateStream;
    timeStream << std::put_time(localTime, "%H:%M:%S");
    dateStream << std::put_time(localTime, "%Y-%m-%d");

    // Vérifier si le fichier existe
    bool fileExists = std::filesystem::exists(filename.str());

    // Ouvrir le fichier de log en mode ajout
    std::ofstream logfile(filename.str(), std::ios::app);

    if (logfile.is_open()) {

        if (!fileExists) {
            if (sensor.getType() == "Temperature") {
                logfile << "Fichier log des capteurs de température\n";
                logfile << "Id, Température °C, Heure, Date\n";
            } else if (sensor.getType() == "Light") {
                logfile << "Fichier log des capteurs de lumière\n";
                logfile << "Id, Intensité lumineuse, Heure, Date\n";
            } else if (sensor.getType() == "Humidity") {
                logfile << "Fichier log des capteurs d'humidité\n";
                logfile << "Id, Humidité %, Heure, Date\n";
            } else if (sensor.getType() == "Sound") {
                logfile << "Fichier log des capteurs de son\n";
                logfile << "Id, Son dB, Heure, Date\n";
            }
        }
        // Écrire les données dans le fichier au format : ID, Type, valeur, heure, date
        logfile << sensor.getId() << ", "  // ID
                << data << ", "              // Valeur
                << timeStream.str() << ", "  // Heure
                << dateStream.str() << std::endl;  // Date
        logfile.close();  // Fermer le fichier
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier " << filename.str() << std::endl;
    }
}

// Récupérer tous les capteurs
const std::vector<Sensor*>& Server::getSensors() const {
    return sensors;
}

// Retourner le nombre de capteurs d'un type donné
int Server::getSensorCount(const std::string& type) const {
    if (type == "Temperature") {
        return sensorCounts[0];
    } else if (type == "Humidity") {
        return sensorCounts[1];
    } else if (type == "Light") {
        return sensorCounts[2];
    } else if (type == "Sound") {
        return sensorCounts[3];
    }
    return 0;  // Aucun capteur de ce type
}

// Recevoir des données génériques
template <typename T>
void Server::receiveData(const Sensor& sensor, T data) {
    // Définir l'unité en fonction du type de capteur
    std::string unite;
    if (sensor.getType() == "Temperature") {
        unite = "°C";
    } else if (sensor.getType() == "Light") {
        unite = "";
    } else if (sensor.getType() == "Humidity") {
        unite = "%";
    } else if (sensor.getType() == "Sound") {
        unite = "dB";
    } else {
        unite = "unite inconnue";  // Cas par défaut si le type est inconnu
    }

    // Afficher les données reçues avec l'unité
    std::cout << "Received data from Sensor " << sensor.getId() << ": " << data << unite << std::endl;

    // Écriture dans le fichier de log
    if constexpr (std::is_same<T, std::string>::value) {
        fileWrite(sensor, data);  // data est déjà une std::string
    } else {
        fileWrite(sensor, std::to_string(data));  // Convertit les autres types en string
    }
}


// Récupérer un capteur par son ID
Sensor* Server::getSensorById(std::string sensorID) {
    for (Sensor* sensor : sensors) {
        if (sensor->getId() == sensorID) {
            return sensor;
        }
    }
    return nullptr;  // Capteur non trouvé
}

// Nécessaire pour que la fonction template soit incluse dans le fichier header
template void Server::receiveData<int>(const Sensor& sensor, int data);
template void Server::receiveData<float>(const Sensor& sensor, float data);
template void Server::receiveData<bool>(const Sensor& sensor, bool data);
template void Server::receiveData<std::string>(const Sensor& sensor, std::string data);