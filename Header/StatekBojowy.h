#ifndef STATEKBOJOWY_H
#define STATEKBOJOWY_H

#include "Kosmoplatan.h"
#include <iostream>


class StatekBojowy 
: public Kosmoplatan
{
public:
    StatekBojowy(const std::string& nazwa, int masa, int mocNapedu, int _silaOgnia)
        : Kosmoplatan(nazwa,masa,mocNapedu), silaOgnia(_silaOgnia){}
    
    double obliczZasieg() const override;
    void wyswietl() const override;

private:
    int silaOgnia;
};
#endif //STATEKBOJOWY_H