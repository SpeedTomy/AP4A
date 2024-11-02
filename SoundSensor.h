#ifndef SOUNDSENSOR_H
#define SOUNDSENSOR_H

#include "Sensor.h"
#include "Data.h"

class SoundSensor : public Sensor {
public:
// Constructor
SoundSensor(Server& server);

// Destructor
virtual ~SoundSensor();

// Constructor par copie
SoundSensor(const SoundSensor& other);

// Opérateur d'assignation par copie
SoundSensor& operator=(const SoundSensor& other);
// Override update to generate temperature data
void update() override;

// Override execute to send temperature data to the server
void execute() override;

private:
Data<int>* data;         // Pointer to the Data object
};

#endif // SOUNDSENSOR_H
