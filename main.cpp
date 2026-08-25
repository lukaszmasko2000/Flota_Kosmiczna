#include <iostream>

#include "Kosmoplatan.h"
#include "CinBuf.h"
#include "Transporter.h"
#include "StatekBojowy.h"
#include "Flota.h"
#include "Menu.h"

int main() {

    // CinBuf buff;
    // {
    //     Menu menu;
    //     menu.uruchomMenu();
    // }

    CinBuf buff;
    Flota flota;
    flota.dodajStatek(std::make_unique<StatekBojowy>("X-Wing", 15, 500, 5));      
    flota.dodajStatek(std::make_unique<Transporter>("Cargomaster", 120, 800, 80)); 
    flota.dodajStatek(std::make_unique<StatekBojowy>("Niszczyciel", 450, 2500, 50)); 
    flota.dodajStatek(std::make_unique<Transporter>("Shuttle-T4", 45, 400, 20)); 

    flota.usunPoMocy(300,2400);

    buff.pressEnter();

    return 0;
}