#include "Server.h"
#include <iostream>
#include <fstream>

// Constructeur par défaut
Server::Server() {}

// Destructeur
Server::~Server() {}

// Constructeur de copie
Server::Server(const Server& other) {}

// Opérateur d'affectation
Server& Server::operator=(const Server& other) {
    if (this != &other) {
        // copier les données si nécessaire
    }
    return *this;
}

// Fonction pour afficher les données dans la console
void Server::consoleWrite(const std::string& data) {
    std::cout << data << std::endl;
}

// Fonction pour écrire les données dans un fichier de log
void Server::fileWrite(const std::string& filename, const std::string& data) {
    std::ofstream logfile(filename, std::ios::app);  // Ouvrir le fichier en mode ajout
    if (logfile.is_open()) {
        logfile << data << std::endl;  // Écrire les données dans le fichier
        logfile.close();               // Fermer le fichier
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier " << filename << std::endl;
    }
}

// Opérateur << pour afficher l'état du serveur
std::ostream& operator<<(std::ostream& os, const Server& server) {
    os << "Server status: OK";
    return os;
}
