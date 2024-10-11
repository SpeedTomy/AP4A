#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <vector>
#include "Sensor.h"

class Sensor;

class Server {
public:
    // Constructeur
    Server();

    // Destructeur
    ~Server();

    // Fonction pour ajouter un capteur
    void addSensor(Sensor& sensor);

    // Fonction pour afficher les données dans la console
    void consoleWrite(const std::string& data);

    // Fonction pour écrire les données dans un fichier de log
    void fileWrite(const std::string& filename, const std::string& data);

    // Fonction pour récupérer les capteurs
    const std::vector<Sensor*>& getSensors() const;

    // Retourner le nombre de capteurs pour un type donné
    int getSensorCount(const std::string& type) const;

    // Utilisation d'un template pour recevoir des données de différents types
    template <typename T>
    void receiveData(int sensorID, T data) {
        std::cout << "Received data from Sensor " << sensorID << ": " << data << std::endl;
    }

private:
    std::vector<Sensor*> sensors;  // Liste de pointeurs vers les capteurs
    std::vector<std::string> dataLog;  // Stocker les données reçues des capteurs
    int sensorCounts[3]; // 0: Temperature, 1: Humidity, 2: Light
};

#endif // SERVER_H
