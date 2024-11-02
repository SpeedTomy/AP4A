#include "TemperatureSensor.h"
#include <cstdlib>  // For rand()
#include <iostream>

// Constructor
TemperatureSensor::TemperatureSensor(Server& server)
: Sensor("Temperature", server) {
data = new Data<float>();  // Initialize a DTemp object
}

// Destructor
TemperatureSensor::~TemperatureSensor() {
delete data; // Libération de la mémoire
}

// Constructor par copie
TemperatureSensor::TemperatureSensor(const TemperatureSensor& other) 
: Sensor(other), data(new Data<float>(*other.data)) {}

// Opérateur d'assignation par copie
TemperatureSensor& TemperatureSensor::operator=(const TemperatureSensor& other) {
if (this != &other) { // Protection contre l'auto-assignation
    Sensor::operator=(other); // Appel de l'opérateur d'assignation de la classe de base
    delete data; // Libère l'ancienne mémoire
    data = new Data<float>(*other.data); // Crée une nouvelle instance de Data en copiant l'instance de l'autre
}
return *this;
}
// Generate temperature data
void TemperatureSensor::update() {
float temperature = static_cast<float>(std::rand() % 1000) / 10.0f;  // Random value between 0.0 and 99.9
data->setData(temperature);  // Update the temperature value

}

// Send temperature data to the server
void TemperatureSensor::execute() {
float temperature = data->getData();  // Get the temperature value
server.receiveData(*this, temperature);
}

