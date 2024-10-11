#include <iostream>
#include "TemperatureSensor.h"
// #include "HumiditySensor.h"
// #include "LightSensor.h"
#include "Scheduler.h"
#include "Server.h"
#include "Sensor.h"

int main() {
    
    // Création du serveur et du scheduler
    Server server;
    Scheduler scheduler(5);

    // Création de capteurs
    TemperatureSensor tempSensor(server);
    // HumiditySensor humiditySensor;
    // LightSensor lightSensor;

    // Ajout des capteurs au scheduler
    scheduler.addSensor(tempSensor);
    // scheduler.addSensor(&humiditySensor);
    // scheduler.addSensor(&lightSensor);

    // Simulation de l'ordonnancement des capteurs
    scheduler.simulation();

    // Écrire des données dans la console et le fichier
    server.consoleWrite("Données envoyées au serveur.");
    server.fileWrite("log_sensor.csv", "2024-10-06,Temperature: " + tempSensor.getData());
    
    return 0;
}
