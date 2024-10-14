#ifndef DATA_H
#define DATA_H

class Data {
public:
    virtual ~Data() {}
    virtual float getData() const = 0;
    virtual void setData(float value) = 0;
};

#endif // DATA_H
