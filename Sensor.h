#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include "Server.h"
#include "Data.h"

class Server;  // Forward declaration

class Sensor {
public:
// Constructor
Sensor(const std::string& type, Server& server);

// Destructor
virtual ~Sensor();

    // Constructor par copie
Sensor(const Sensor& other);

// Opérateur d'assignation par copie
Sensor& operator=(const Sensor& other);

// Pure virtual method to update sensor data
virtual void update() = 0;

// Pure virtual method to execute the sensor's task
virtual void execute() = 0;

// Accessor for the sensor type
std::string getType() const;

// Returns the sensor's unique ID
std::string getId() const;

protected:
std::string id;             // Unique ID of the sensor
std::string type;   // Sensor type (e.g., Temperature, Light, etc.)
Server& server;     // Reference to the server
};

#endif // SENSOR_H
