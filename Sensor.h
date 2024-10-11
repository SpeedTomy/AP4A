#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include "Server.h"

class Server;

template <typename T>

class Sensor {
public:
    // Constructeur
    Sensor(const std::string& type, Server& server);

    // Destructeur
    virtual ~Sensor();

    // Méthode d'activation (mise à jour des données du capteur)
    virtual void update() = 0;

    // Méthode d'exécution qui génère les données
    virtual void execute() = 0;

   // Méthode pour récupérer les données du capteur
    T getData() const;

    // Accesseur pour l'attribut type
    std::string getType() const;

     // Retourne l'ID unique du capteur
    int getId() const;

protected:
    int id;  // Compteur statique pour les ID des capteurs
    std::string type;
    T data;  // Donnée de type générique
    Server& server;  // Référence à un serveur
};

// Implémentation du constructeur
template <typename T>
Sensor<T>::Sensor(const std::string& type, Server& server)
    : type(type), server(server) {

    // Lors de la création, demander au serveur combien de capteurs de ce type existent
    id = server.getSensorCount(type) + 1;  // L'ID est le nombre actuel de capteurs de ce type + 1
    server.addSensor(*this);  // Ajouter le capteur au serveur 
}

// Implémentation du destructeur
template <typename T>
Sensor<T>::~Sensor() {}


// Retourne les données du capteur
template <typename T>
T Sensor<T>::getData() const {
    return data;
}

// Retourne le type du capteur
template <typename T>
std::string Sensor<T>::getType() const {
    return type;
}

// Retourne l'ID unique du capteur
template <typename T>
int Sensor<T>::getId() const {
    return id;
}

#endif // SENSOR_H
