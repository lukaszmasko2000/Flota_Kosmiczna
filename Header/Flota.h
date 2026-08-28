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
    [[maybe_unused]]    int zliczPowyzejMocy(int) const;
    [[maybe_unused]]    int zliczPonizejMocy(int) const;
    [[maybe_unused]]    int zliczPowyzejMasy(int) const;
    [[maybe_unused]]    int zliczPonizejMasy(int) const;
    [[maybe_unused]]    int zliczPowyzejZasiegu(int) const;
    [[maybe_unused]]    int zliczPonizejZasiegu(int) const;

    [[nodiscard]]   int zliczMoc(int,int) const;
    [[nodiscard]]   int zliczMase(int,int) const;
    [[nodiscard]]   int zliczZasieg(int,int) const;

    //Remove If
    void usunCiezkie(int);

    void usunPoMasie(int,int);
    void usunPoZasiegu(int,int);
    void usunPoMocy(int,int);
    void usunPoNazwie(std::string);

    //Accumulate
    [[nodiscard]] int obliczCalkowitaMoc() const;
    [[nodiscard]] int obliczCalkowitaMase() const;
    [[nodiscard]] int obliczCalkowityZasieg() const;

    //Show If
    void pobierzSzybkieStatki(double);

    void pobierzStatkiPoMocy(double,double) const;
    void pobierzStatkiPoMasie(double,double) const;
    void pobierzStatkiPoZasiegu(double,double) const;
    void pobierzStatkiPoLiterce(char) const;

    //Transform
    void eksportujNazwy() const;
    void eksportujMoc() const;
    void eksportujZasieg() const;
    void eksportujMase() const;


private:
    std::vector<std::unique_ptr<Kosmoplatan>> statki;

};

#endif // FLOTA_H