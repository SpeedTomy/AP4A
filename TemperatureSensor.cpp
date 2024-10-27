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
    // The base class destructor will delete the data object
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

