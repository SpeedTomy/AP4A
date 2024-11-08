#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include <string>
#include "Sensor.h"
#include <map>

class Sensor;  // Déclaration anticipée de la classe Sensor

class Server {
public:
// Constructeur et destructeur
Server();
 // Destructeur
~Server();
// Constructeur par copie
Server(const Server& other);
// Opérateur d'assignation par copie
Server& operator=(const Server& other);

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

std::map<std::string, int> sensorCounts;

// Récupérer un capteur par son ID
Sensor* getSensorById(std::string sensorID);
};

#endif // SERVER_H
