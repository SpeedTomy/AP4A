#include "LightSensor.h"
#include <cstdlib>  // For rand()
#include <iostream>

// Constructor
LightSensor::LightSensor(Server& server)
: Sensor("Light", server) {
data = new Data<std::string>();
}

// Destructor
LightSensor::~LightSensor() {
delete data; // Libération de la mémoire
}

// Constructor par copie
LightSensor::LightSensor(const LightSensor& other) 
: Sensor(other), data(new Data<std::string>(*other.data)) {}

// Opérateur d'assignation par copie
LightSensor& LightSensor::operator=(const LightSensor& other) {
if (this != &other) { // Protection contre l'auto-assignation
Sensor::operator=(other); // Appel de l'opérateur d'assignation de la classe de base
delete data; // Libère l'ancienne mémoire
data = new Data<std::string>(*other.data); // Crée une nouvelle instance de Data en copiant l'instance de l'autre
}
return *this;
}

// Generate Light data
void LightSensor::update() {
bool Light = static_cast<bool>(std::rand() % 2);  // Random value between 0 and 120dB
std::string lightStatus = Light ? "On" : "Off";  // Set the light status
data->setData(lightStatus);  // Update the Light value
}

// Send Light data to the server
void LightSensor::execute() {
std::string Light = data->getData();  // Get the Light value
server.receiveData(*this, Light);

}

