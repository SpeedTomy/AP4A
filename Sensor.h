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

    // Pure virtual method to update sensor data
    virtual void update() = 0;

    // Pure virtual method to execute the sensor's task
    virtual void execute() = 0;

    // Méthode pour obtenir la donnée
    virtual float getData() const = 0;

    // Accessor for the sensor type
    std::string getType() const;

    // Returns the sensor's unique ID
    int getId() const;

protected:
    int id;             // Unique ID of the sensor
    std::string type;   // Sensor type (e.g., Temperature, Light, etc.)
    Server& server;     // Reference to the server
    Data* data;         // Pointer to the Data object
};

#endif // SENSOR_H
