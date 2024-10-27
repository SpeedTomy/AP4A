#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include "Sensor.h"
#include "Data.h"

class HumiditySensor : public Sensor {
public:
    // Constructor
    HumiditySensor(Server& server);

    // Destructor
    virtual ~HumiditySensor();

    // Override update to generate humidity data
    void update() override;

    // Override execute to send humidity data to the server
    void execute() override;

private:
    Data<float>* data;         // Pointer to the Data object
};

#endif // HUMIDITYSENSOR_H
