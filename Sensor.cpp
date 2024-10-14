#include "Sensor.h"
#include "Server.h"

// Constructor
Sensor::Sensor(const std::string& type, Server& server)
    : type(type), server(server), data(nullptr) {
    // Initialize ID based on the number of existing sensors of this type
    id = server.getSensorCount(type) + 1;
    server.addSensor(*this);  // Add the sensor to the server
}

// Destructor
Sensor::~Sensor() {
    delete data;  // Ensure proper cleanup of the Data object
}

// Get the sensor type
std::string Sensor::getType() const {
    return type;
}

// Get the unique sensor ID
int Sensor::getId() const {
    return id;
}
