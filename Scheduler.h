#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Sensor.h"
#include <vector>

class Scheduler {
public:
    // Constructeur
    Scheduler(int interval);

    // Destructeur
    ~Scheduler();

    // Ajouter un capteur
    void addSensor(Sensor& sensor);

    // Démarre la simulation
    void simulation();

private:
    int interval;  // Intervalle de mise à jour des capteurs
    std::vector<Sensor*> sensors;  // Liste des capteurs gérés par le scheduler
};

#endif
