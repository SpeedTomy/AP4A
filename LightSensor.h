#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include "Sensor.h"
#include "Data.h"

class LightSensor : public Sensor {
public:
// Constructor
LightSensor(Server& server);

// Destructor
virtual ~LightSensor();

// Constructor par copie
LightSensor(const LightSensor& other);

// Opérateur d'assignation par copie
LightSensor& operator=(const LightSensor& other);

// Override update to generate temperature data
void update() override;

// Override execute to send temperature data to the server
void execute() override;

private:
Data<std::string>* data;         // Pointer to the Data object
};

#endif // TEMPERATURESENSOR_H
