#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "Sensor.h"
#include "Data.h"

class TemperatureSensor : public Sensor {
public:
    // Constructor
    TemperatureSensor(Server& server);

    // Destructor
    virtual ~TemperatureSensor();

    // Override update to generate temperature data
    void update() override;

    // Override execute to send temperature data to the server
    void execute() override;

    // Surcharge de getData() pour récupérer la température
    float getData() const override; // La méthode retourne la valeur de température
};

#endif // TEMPERATURESENSOR_H
