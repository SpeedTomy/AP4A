#ifndef DATA_H
#define DATA_H


template <typename T> class Data {
public:
     Data() : data(T()) {}  // Initialise avec la valeur par défaut du type T
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
