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
    // The base class destructor will delete the data object
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

