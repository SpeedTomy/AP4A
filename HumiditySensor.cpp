#include "HumiditySensor.h"
#include <cstdlib>  // For rand()
#include <iostream>

// Constructor
HumiditySensor::HumiditySensor(Server& server)
: Sensor("Humidity", server) {
data = new Data<float>();
}

// Destructor
HumiditySensor::~HumiditySensor() {
delete data; // Libération de la mémoire
}

// Constructor par copie
HumiditySensor::HumiditySensor(const HumiditySensor& other) : Sensor(other) {
data = new Data<float>(*other.data); // Crée une nouvelle instance de Data en copiant l'instance de l'autre
}

// Opérateur d'assignation par copie
HumiditySensor& HumiditySensor::operator=(const HumiditySensor& other) {
if (this != &other) { // Protection contre l'auto-assignation
    Sensor::operator=(other); // Appel de l'opérateur d'assignation de la classe de base
    delete data; // Libère l'ancienne mémoire
    data = new Data<float>(*other.data); // Crée une nouvelle instance de Data en copiant l'instance de l'autre
}
return *this;
}

// Generate humidity data
void HumiditySensor::update() {
float humidity = static_cast<float>(std::rand() % 101);  // Random value between 0 and 100
data->setData(humidity);  // Update the humidity value

}

// Send humidity data to the server
void HumiditySensor::execute() {
float humidity = data->getData();  // Get the humidity value
server.receiveData(*this, humidity);

}

