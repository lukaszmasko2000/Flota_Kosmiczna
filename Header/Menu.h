#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <memory>
#include <string>
#include <iomanip>

#include "Flota.h"
#include "Kosmoplatan.h"
#include "StatekBojowy.h"
#include "Transporter.h"

class Menu
{
public:
    Menu() = default;
    ~Menu() = default;
    void wyswietlMenu() const;
    void uruchomMenu();

    void addStatekBojowy();
    void addTransporter();
    void zliczStatkiPowyzejMocy();
    void usunCiezkieStatki();
    void pobierzSzybkieStatki();

private:
    Flota flota;
    void stop() const;

};
#endif // MENU_H