#ifndef KOSMOPLATAN_H
#define KOSMOPLATAN_H

#include <iostream>


//TODO TOMMOROW
// Change std::cout to std::print
// And maybe prepare to add more algortihm fuctions at Flota class, but do it later 


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

    [[nodiscard]] const std::string& getNazwa() const { return nazwa; }
    [[nodiscard]] int getMasa() const { return masa; }
    [[nodiscard]] int getMocNapedu() const { return mocNapedu; }

private:
    std::string nazwa;
    int masa;
    int mocNapedu;
};
#endif //KOSMOPLATAN_H