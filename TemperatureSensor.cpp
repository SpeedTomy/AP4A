#include "TemperatureSensor.h"
#include <cstdlib>
#include <iostream>

// Constructeur
TemperatureSensor::TemperatureSensor(Server& server) 
    : Sensor<float>("Temperature", server) {}

// Génère une nouvelle donnée aléatoire pour le capteur de température
void TemperatureSensor::update() {
    // Génère une température aléatoire en tant que float entre 0.0 et 99.9
    float temperature = static_cast<float>(std::rand() % 1000) / 10.0f;  // Valeur entre 0.0 et 99.9

    // Assigne la température directement au membre 'data' (qui est maintenant de type float)
    data = temperature;

    // Affiche la nouvelle température générée dans la console
    std::cout << "TempSensor ID " << id << " met à jour sa donnée: " << data << "°C" << std::endl;
}


// Implémentation de la méthode execute
void TemperatureSensor::execute() {
    // Envoie les données au serveur
    server.receiveData(id, data);

    // Affiche dans la console
    std::cout << "TempSensor ID " << id << " envoie des données: " << data << std::endl;
}