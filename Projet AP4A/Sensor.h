#ifndef SENSOR_H
#define SENSOR_H

#include <string>


class Sensor {
public:
    Sensor() {}
    ~Sensor() {}

    std::string getData() const {
        return "22°C";  // Exemple de donnée simulée
    }
};

#endif // SENSOR_H
