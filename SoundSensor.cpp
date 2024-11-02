#include "SoundSensor.h"
#include <cstdlib>  // For rand()
#include <iostream>

// Constructor
SoundSensor::SoundSensor(Server& server)
: Sensor("Sound", server) {
data = new Data<int>();  
}

// Destructor
SoundSensor::~SoundSensor() {
delete data; // Libération de la mémoire
}
// Constructor par copie
SoundSensor::SoundSensor(const SoundSensor& other) 
: Sensor(other), data(new Data<int>(*other.data)) {}

// Opérateur d'assignation par copie
SoundSensor& SoundSensor::operator=(const SoundSensor& other) {
if (this != &other) { // Protection contre l'auto-assignation
    Sensor::operator=(other); // Appel de l'opérateur d'assignation de la classe de base
    delete data; // Libère l'ancienne mémoire
    data = new Data<int>(*other.data); // Crée une nouvelle instance de Data en copiant l'instance de l'autre
}
return *this;
}

// Generate sound data
void SoundSensor::update() {
int sound = static_cast<int>(std::rand() % 121);  // Random value between 0 and 120dB
data->setData(sound);  // Update the sound value

}

// Send sound data to the server
void SoundSensor::execute() {
int sound = data->getData();  // Get the sound value
server.receiveData(*this, sound);

}

