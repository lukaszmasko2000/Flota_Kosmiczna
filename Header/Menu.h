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
    Add_Warship = 1,
    Add_Transporter,
    Show_The_Navy,               
    Sort_By_Range,
    Count_Starships_Above_Power,
    Remove_Heavy_Starships,
    Calculate_The_Total_Power,
    Download_Fast_Starships,
    Export_Every_Starship_Name,
    Exit = 0
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

    std::unordered_map<Choose_Option, std::function<void()>> actions {
        {Choose_Option::Add_Warship, [this] { 
            buff.clearScreen(); 
            addStatekBojowy(); 
            buff.pressEnter(); 
        }},
        {Choose_Option::Add_Transporter, [this] { 
            buff.clearScreen(); 
            addTransporter(); 
            buff.pressEnter(); 
        }},
        {Choose_Option::Show_The_Navy, [this] { 
            buff.clearScreen(); 
            flota.wyswietlFlote(); 
            buff.pressEnter(); 
        }},
        {Choose_Option::Sort_By_Range, [this] { 
            buff.clearScreen(); 
            flota.sortujPoZasiegu(); 
            buff.pressEnter(); 
        }},
        {Choose_Option::Count_Starships_Above_Power, [this] { 
            buff.clearScreen(); 
            zliczStatkiPowyzejMocy(); 
            buff.pressEnter(); 
        }},
        {Choose_Option::Remove_Heavy_Starships, [this] { 
            buff.clearScreen(); 
            usunCiezkieStatki(); 
            buff.pressEnter(); 
        }},
        {Choose_Option::Calculate_The_Total_Power, [this] { 
            buff.clearScreen(); 
            std::print("Całkowita moc floty: {} MW\n", flota.obliczCalkowitaMoc()); 
            buff.pressEnter(); 
        }},
        {Choose_Option::Download_Fast_Starships, [this] { 
            buff.clearScreen(); 
            pobierzSzybkieStatki(); 
            buff.pressEnter(); 
        }},
        {Choose_Option::Export_Every_Starship_Name, [this] { 
            buff.clearScreen(); 
            flota.eksportujNazwy(); 
            buff.pressEnter(); }},
        {Choose_Option::Exit, [this] { 
            buff.clearScreen(); 
            std::print("Wyjście z programu.\n"); 
            buff.pressEnter(); 
        }}
    };

};
#endif // MENU_H