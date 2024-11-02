#ifndef DATA_H
#define DATA_H

template <typename T>
class Data {
public:
// Constructeur par défaut
Data() : data(T()) {}  // Initialise avec la valeur par défaut du type T

// Constructeur par copie
Data(const Data& other) : data(other.data) {}

// Opérateur d'assignation par copie
Data& operator=(const Data& other) {
    if (this != &other) { // Protection contre l'auto-assignation
        data = other.data;
    }
    return *this;
}

// Destructeur
~Data() {}

T getData() const {
    return data;
}

void setData(T value) {
    data = value;
}

private:
T data;
};

#endif // DATA_H
