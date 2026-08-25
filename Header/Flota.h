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
#include <print>


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


    /*----TODO---*/
    // Think about how to solve some problems with functions
    // How to for example find ships by numbers from string and solve other problems.
    // And then I'll make the interface of the app.


    //Show
    void wyswietlFlote() const;

    //Sort By
    void sortujPoZasiegu_Rosnaco();
    void sortujPoZasiegu_Malejaco();
    void sortujPoMasie_Rosnaco();
    void sortujPoMasie_Malejaco();
    void sortujPoNazwie_Rosnaco();
    void sortujPoNazwie_Malejaco();
    void sortujPoMocyNapedu_Rosnaco();
    void sortujPoMocyNapedu_Malejaco();

    //Count If
    int zliczPowyzejMocy(int) const;
    int zliczPonizejMocy(int) const;
    int zliczPowyzejMasy(int) const;
    int zliczPonizejMasy(int) const;
    int zliczPowyzejZasiegu(int) const;
    int zliczPonizejZasiegu(int) const;

    //Remove If
    void usunCiezkie(int);
    void usunPoZasiegu(int);
    void usunPoMocy(int);
    void usunPoNazwie(std::string);

    //Accumulate
    int obliczCalkowitaMoc() const;
    int obliczCalkowitaMase() const;
    int obliczCalkowityZasieg() const;

    //Show If
    void pobierzSzybkieStatki(double);
    void pobierzStatkiPoMasie(double);
    void pobierzStatkiPoZasiegu(double);
    void pobierzStatkiPoLiterce(std::string);

    //Transform
    void eksportujNazwy() const;
    void eksportujMoc() const;
    void eksportujZasieg() const;
    void eksportujMase() const;


private:
    std::vector<std::unique_ptr<Kosmoplatan>> statki;

};

#endif // FLOTA_H