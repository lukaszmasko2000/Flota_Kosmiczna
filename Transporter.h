#ifndef TRANSPORTER_H
#define TRANSPORTER_H

#include "Kosmoplatan.h"
#include <iostream>

class Transporter 
    : public Kosmoplatan
{
public:
    Transporter(const std::string& nazwa, int masa, int mocNapedu, int _ladownosc)
        : Kosmoplatan(nazwa,masa,mocNapedu) , ladownosc(_ladownosc){}
    
private:
    int ladownosc;
};
#endif //TRANSPORTER_H