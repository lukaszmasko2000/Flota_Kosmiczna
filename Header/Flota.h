#ifndef FLOTA_H
#define FLOTA_H


#include "Kosmoplatan.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <string>
#include <memory>


using namespace std::string_literals;



//TODO TOMMOROW
//I'll add smart pointers instead of manual allocation

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
        std::cout << "\n--- Automatyczne czyszczenie pamieci Floty (unique_ptr) ---" << std::endl;
    }


    void dodajStatek(std::unique_ptr<Kosmoplatan> s)
    {
        if(s) statki.push_back(std::move(s));
    }


    void wyswietlFlote() const;
    void sortujPoZasiegu();
    int zliczPowyzejMocy(int) const;
    void usunCiezkie(int);
    int obliczCalkowitaMoc() const;
    void pobierzSzybkieStatki(std::vector<Kosmoplatan*>&, double) const;
    void eksportujNazwy() const;


private:
    std::vector<std::unique_ptr<Kosmoplatan>> statki;

};

#endif // FLOTA_H