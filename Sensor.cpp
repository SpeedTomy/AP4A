#include "Sensor.h"
#include "Server.h"

// Constructor
Sensor::Sensor(const std::string& type, Server& server)
    : type(type), server(server){
     int count = server.getSensorCount(type) + 1;  // Incrémente le nombre de capteurs du même type
    id = std::to_string(count) + "_" + type;      // Génère un ID unique basé sur le compteur et le type
    server.addSensor(*this);  // Add the sensor to the server
}

// Destructor
Sensor::~Sensor() {}

// Get the sensor type
std::string Sensor::getType() const {
    return type;
}

// Get the unique sensor ID
std::string Sensor::getId() const {
    return id;
}
