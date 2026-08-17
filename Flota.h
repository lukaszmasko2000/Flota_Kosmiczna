#ifndef FLOTA_H
#define FLOTA_H


#include "Kosmoplatan.h"


struct KryteriumMocy{
    int progMocy;

    KryteriumMocy(int p) 
        : progMocy(p){}
    
    bool operator()(const Kosmoplatan* statek) const{
        if (statek->getMocNapedu() > progMocy) return true;
        return false;
    }
};

struct EkstraktorNazwy{


};


class Flota
{





};

#endif // FLOTA_H