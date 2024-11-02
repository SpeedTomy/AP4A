#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include "LightSensor.h"
#include "SoundSensor.h"

#include "Scheduler.h"
#include "Server.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <windows.h>

int main() {

// Activer l'UTF-8 pour la console Windows afin de gérer l'affichage des unités
SetConsoleOutputCP(CP_UTF8);

// Demarrage de la fonction aléatoire
std::srand(static_cast<unsigned int>(std::time(nullptr)));

// Création du serveur et du scheduler
Server server;
Scheduler scheduler(3000);  // Intervalle de mise à jour des capteurs

// Création des capteurs
TemperatureSensor tempSensor(server);  // On passe directement le serveur au constructeur
HumiditySensor humiditySensor(server); // Exemple pour le capteur d'humidité
SoundSensor soundSensor(server);
LightSensor lightsensor(server);

// Ajout des capteurs au scheduler
scheduler.addSensor(tempSensor);
scheduler.addSensor(humiditySensor);
scheduler.addSensor(soundSensor);
scheduler.addSensor(lightsensor);

// Simulation de l'ordonnancement des capteurs
scheduler.simulation();

// Écrire des données dans la console et dans le fichier
server.consoleWrite("Données envoyées au serveur.");

return 0;
}
