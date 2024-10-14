#include "Data.h"


// Classe pour gérer la donnée de température
class DTemp : public Data {
public:
    float getData() const override { return data; }
    void setData(float value) override { data = value; }

private:
    float data;
};

// Classe pour gérer la donnée de lumière
class DLight : public Data {
public:
    float getData() const override { return data; }
    void setData(float value) override { data = value; }

private:
    float data;
};



// Classe pour gérer la donnée d'humidité
class DHumidity : public Data {
public:
    float getData() const override { return data; }
    void setData(float value) override { data = value; }

private:
    float data;
};
