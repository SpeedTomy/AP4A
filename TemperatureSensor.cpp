#include "TemperatureSensor.h"
#include <cstdlib>  // For rand()
#include <iostream>
#include "Data.cpp"

// Constructor
TemperatureSensor::TemperatureSensor(Server& server)
    : Sensor("Temperature", server) {
    data = new DTemp();  // Initialize a DTemp object
}

// Destructor
TemperatureSensor::~TemperatureSensor() {
    // The base class destructor will delete the data object
}

// Generate temperature data
void TemperatureSensor::update() {
    float temperature = static_cast<float>(std::rand() % 1000) / 10.0f;  // Random value between 0.0 and 99.9
    dynamic_cast<DTemp*>(data)->setData(temperature);  // Update the temperature value

    std::cout << "TempSensor ID " << id << " updated data: " << temperature << "°C" << std::endl;
}

// Send temperature data to the server
void TemperatureSensor::execute() {
    float temperature = dynamic_cast<DTemp*>(data)->getData();  // Get the temperature value
    server.receiveData(id, temperature);

    std::cout << "TempSensor ID " << id << " sent data: " << temperature << std::endl;
}


// Surcharge de getData() pour retourner la donnée spécifique du capteur
float TemperatureSensor::getData() const {
    return dynamic_cast<DTemp*>(data)->getData();  // Récupère la température
}
