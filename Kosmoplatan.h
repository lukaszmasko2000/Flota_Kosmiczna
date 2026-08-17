#ifndef KOSMOPLATAN_H
#define KOSMOPLATAN_H

#include <iostream>



class Kosmoplatan
{
public:
    Kosmoplatan(const std::string& _nazwa, int _masa, int _mocNapedu)
        : nazwa(_nazwa), masa(_masa), mocNapedu(_mocNapedu){}

    virtual ~Kosmoplatan(){
        std::cout << "[Destruktor] Usuwanie obiektu: " << nazwa << std::endl;
    }

    virtual double obliczZasieg() const = 0;
    virtual void wyswietl() const = 0;

private:
    std::string nazwa;
    int masa;
    int mocNapedu;
};
#endif //KOSMOPLATAN_H