#ifndef SERVER_H
#define SERVER_H

#include <string>

class Server {
public:
    // Constructeurs et destructeurs
    Server();
    ~Server();
    Server(const Server& other);
    Server& operator=(const Server& other);

    // Méthodes pour écrire dans la console et dans les fichiers
    void consoleWrite(const std::string& data);
    void fileWrite(const std::string& filename, const std::string& data);

    // Opérateur << pour rediriger les flux
    friend std::ostream& operator<<(std::ostream& os, const Server& server);
};

#endif // SERVER_H

