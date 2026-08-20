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
#include <ranges>
#include <utility>


using namespace std::string_literals;

class Flota
{
public:
    Flota() = default;
    ~Flota() {
        std::println("{:-^59}", " Automatyczne czyszczenie pamieci Floty (unique_ptr) ");
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
    void pobierzSzybkieStatki(double);
    void eksportujNazwy() const;


private:
    std::vector<std::unique_ptr<Kosmoplatan>> statki;

};

#endif // FLOTA_H