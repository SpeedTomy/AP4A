#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include <string>
#include "Sensor.h"

class Sensor;  // Déclaration anticipée de la classe Sensor

class Server {
public:
    // Constructeur et destructeur
    Server();
    ~Server();

    // Ajouter un capteur au serveur
    void addSensor(Sensor& sensor);

    // Afficher des données dans la console
    void consoleWrite(const std::string& data);

    // Écrire des données dans un fichier de log spécifique à chaque capteur
    void fileWrite(const Sensor& sensor, const std::string& data);

    // Récupérer tous les capteurs
    const std::vector<Sensor*>& getSensors() const;

    // Retourner le nombre de capteurs d'un type donné
    int getSensorCount(const std::string& type) const;

    // Recevoir des données génériques
    template <typename T>
    void receiveData(const Sensor& sensor, T data);

private:
    // Liste des capteurs enregistrés
    std::vector<Sensor*> sensors;

    // Compteurs pour le nombre de capteurs de chaque type
    int sensorCounts[4];  // [0] : Temperature, [1] : Humidity, [2] : Light, [3] : Sound

    // Récupérer un capteur par son ID
    Sensor* getSensorById(std::string sensorID);
};

#endif // SERVER_H
