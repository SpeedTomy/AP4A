#include "Scheduler.h"
#include <iostream>
#include <thread>
#include <chrono>

// Constructeur
Scheduler::Scheduler(int interval) : interval(interval) {}

// Destructeur
Scheduler::~Scheduler() {
    // Libérer les ressources dynamiques
    for (Sensor* sensor : sensors) {
        delete sensor;  // Supprimer chaque capteur
    }
    sensors.clear();  // Vider la liste des capteurs
}

// Ajouter un capteur à la liste
void Scheduler::addSensor(Sensor& sensor) {
    sensors.push_back(&sensor);
}

// Démarre la simulation
void Scheduler::simulation() {
    while (true) {  // Boucle infinie pour continuer tant que le programme n'est pas arrêté
        for (auto& sensor : sensors) {
            
            sensor->update();  // Mettre à jour les capteurs
            sensor->execute(); // Exécuter l'envoi de données
        }

        // Attendre l'intervalle spécifié entre chaque mesure
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));

        // Afficher un message pour indiquer que la simulation est en cours

        std::cout << "\n\t Nouvelle Simulation :" << std::endl;
    }
}

