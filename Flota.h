#ifndef FLOTA_H
#define FLOTA_H


using namespace std::string_literals;

#include "Kosmoplatan.h"
#include <vector>
#include <algorithm>



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
public:
    Flota() = default;
    ~Flota() {
        std::cout << "\n--- Czyszczenie pamieci Floty ---" << std::endl;
        std::for_each(statki.begin(), statki.end(), [](Kosmoplatan* ptr) {delete ptr;});
        statki.clear();
    }


    void dodajStatek(Kosmoplatan* s)
    {
        if(s) statki.push_back(s);
    }


    void wyswietlFlote() const;
    void sortujPoZasiegu() const;
    int zliczPowyzejMocy(int) const;
    void usunCiezkie(int);
    int obliczCalkowitaMoc() const;
    void pobierzSzybkieStatki(std::vector<Kosmoplatan*>&, double) const;
    void eksportujNazwy() const;


private:
    std::vector<Kosmoplatan*> statki;

};

#endif // FLOTA_H