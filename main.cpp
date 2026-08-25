#include <iostream>

#include "Kosmoplatan.h"
#include "CinBuf.h"
#include "Transporter.h"
#include "StatekBojowy.h"
#include "Flota.h"
#include "Menu.h"

int main() {

     CinBuf buff;
    //  {
    //      Menu menu;
    //      menu.uruchomMenu();
    // }

    Flota flota;

        flota.dodajStatek(std::make_unique<StatekBojowy>("X-Wing", 15, 500, 5));      
        flota.dodajStatek(std::make_unique<Transporter>("Cargomaster", 120, 800, 80)); 
        flota.dodajStatek(std::make_unique<StatekBojowy>("Niszczyciel", 450, 2500, 50)); 
        flota.dodajStatek(std::make_unique<Transporter>("Shuttle-T4", 45, 400, 20)); 
    
    flota.pobierzStatkiPoMocy(400,2600);
    //flota.usunPoMocy(400,2600);

    buff.pressEnter();

    return 0;
}