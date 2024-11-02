#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "Sensor.h"
#include "Data.h"

class TemperatureSensor : public Sensor {
public:
  // Constructor
  TemperatureSensor(Server& server);

  // Destructor
  virtual ~TemperatureSensor();

// Constructor par copie
  TemperatureSensor(const TemperatureSensor& other);

  // Opérateur d'assignation par copie
  TemperatureSensor& operator=(const TemperatureSensor& other);
  
  // Override update to generate temperature data
  void update() override;

  // Override execute to send temperature data to the server
  void execute() override;

private:
  Data<float>* data;         // Pointer to the Data object
};

#endif // TEMPERATURESENSOR_H
