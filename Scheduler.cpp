#include "Scheduler.h"
#include <iostream>
#include <thread>
#include <chrono>

// Constructeur
Scheduler::Scheduler(int interval) : interval(interval) {}

// Destructeur 
Scheduler::~Scheduler() {
    // Libérer les ressources dynamiques (par exemple, supprimer les capteurs)
    for (Sensor* sensor : sensors) {
        delete sensor;  // Suppression de chaque capteur
    }
    sensors.clear();  // Vide la liste des capteurs
}
// Ajouter un capteur à la liste des capteurs gérés par le Scheduler
void Scheduler::addSensor(Sensor& sensor) {
    sensors.push_back(&sensor);
}

// Démarre la simulation
void Scheduler::simulation() {
    int maxIterations = 10;  // Nombre maximum d'itérations
    int iterations = 0;

    while (iterations < maxIterations) {
        for (auto& sensor : sensors) {
            sensor->update();
            sensor->execute();  // Mise à jour des capteurs
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Pause
        iterations++;
        std::cout << "Simulation en cours..." << std::endl;
    }

}