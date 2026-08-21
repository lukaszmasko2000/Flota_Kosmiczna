#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <memory>
#include <string>
#include <print>
#include <functional>
#include <unordered_map>

#include "Flota.h"
#include "Kosmoplatan.h"
#include "StatekBojowy.h"
#include "Transporter.h"
#include "CinBuf.h"


enum class Choose_Option {
    Add_Warship = 0,
    Add_Transporter,
    Show_The_Navy,               
    Sort_By_Range,
    Count_Starships_Above_Power,
    Remove_Heavy_Starships,
    Calculate_The_Total_Power,
    Download_Fast_Starships,
    Export_Every_Starship_Name,
    Exit
};                               


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
    CinBuf buff;

};
#endif // MENU_H