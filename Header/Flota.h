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


    //Show
    void wyswietlFlote() const;

    //Sort By
    void sortujPoZasiegu_Rosnaco();
    void sortujPoZasiegu_Malejaco();
    void sortujPoMasie_Rosnaco();
    void sorturPoMasie_Malejaco();
    void sortujPoNazwie_Rosnaco();
    void sortujPoNazwie_Malejaco();
    void sortujPoMocyNapedu_Rosnaco();
    void sortujPoMocyNapedu_Malejaco();

    //Count If
    int zliczPowyzejMocy(int) const;

    //Remove If
    void usunCiezkie(int);

    //Accumulate
    int obliczCalkowitaMoc() const;

    //Show If
    void pobierzSzybkieStatki(double);

    //Transform
    void eksportujNazwy() const;


private:
    std::vector<std::unique_ptr<Kosmoplatan>> statki;

};

#endif // FLOTA_H