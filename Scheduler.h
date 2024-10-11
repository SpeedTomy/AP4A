#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Sensor.h"
#include "Server.h"

class Scheduler {
public:
    // Constructeur
    Scheduler(int interval);

    // Destructeur
    virtual ~Scheduler();

    // Démarre la simulation
    void simulation();

    // Ajouter un capteur au Scheduler
    void addSensor(Sensor& sensor);

private:
    int interval;  // Intervalle de temps entre chaque mise à jour des capteurs (en secondes)
    std::vector<Sensor*> sensors;  // Liste des capteurs à planifier
};

#endif // SCHEDULER_H
