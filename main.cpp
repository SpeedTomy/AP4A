#include "TemperatureSensor.h"
//#include "HumiditySensor.h"
//#include "LightSensor.h"
#include "Scheduler.h"
#include "Server.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    // Création du serveur et du scheduler
    Server server;
    Scheduler scheduler(10000);  // Intervalle de mise à jour des capteurs

    // Création des capteurs
    TemperatureSensor tempSensor(server);  // On passe directement le serveur au constructeur
   // HumiditySensor humiditySensor(server); // Exemple pour le capteur d'humidité
  //  LightSensor lightSensor(server);       // Exemple pour le capteur de lumière

    // Ajout des capteurs au scheduler
    scheduler.addSensor(tempSensor);
  //  scheduler.addSensor(humiditySensor);
  //  scheduler.addSensor(lightSensor);

    // Simulation de l'ordonnancement des capteurs
    scheduler.simulation();

    // Écrire des données dans la console et dans le fichier
    server.consoleWrite("Données envoyées au serveur.");

    // Ces lignes loguent dans les fichiers spécifiques à chaque capteur
    server.fileWrite(tempSensor, "Temperature: " + std::to_string(tempSensor.getData()));
   // server.fileWrite(humiditySensor, "Humidity: " + std::to_string(humiditySensor.getData()));
   // server.fileWrite(lightSensor, "Light: " + std::to_string(lightSensor.getData()));

    return 0;
}
