#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "Sensor.h"

class TemperatureSensor : public Sensor<float> {
public:

    // Constructeur
    TemperatureSensor(Server& server);

    // Méthode de mise à jour (génère une nouvelle donnée aléatoire)
    void update() override;

    // Méthode pour envoyer les données au serveur
    void execute() override;
};

#endif // TEMPERATURESENSOR_H
