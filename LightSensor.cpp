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
    // The base class destructor will delete the data object
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

