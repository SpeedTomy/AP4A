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
    // The base class destructor will delete the data object
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

