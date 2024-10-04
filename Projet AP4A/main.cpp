#include "Server.h"
#include "Sensor.h"
#include "Scheduler.h"

int main() {
    Server server;
    Sensor sensor;

    std::string data = sensor.getData();

    // Affichage dans la console
    server.consoleWrite("Donnée reçue : " + data);

    // Écriture dans le fichier de log
    server.fileWrite("log_sensor.csv", "2024-09-12," + data);

    return 0;
}
