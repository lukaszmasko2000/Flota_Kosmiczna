#ifndef FLOTA_H
#define FLOTA_H


using namespace std::string_literals;

#include "Kosmoplatan.h"
#include <vector>


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

    std::string operator()(const Kosmoplatan* statek) const{
        if (statek) return statek->getNazwa();
        return ""s;
    }

};


class Flota
{




private:
    std::vector<Kosmoplatan*> statki;

};

#endif // FLOTA_H