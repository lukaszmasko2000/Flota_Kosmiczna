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


//TODO
// I want to add more options. I mean I can sort ships in more ways like for example:
// Sort By Range (Decreasing/Increasing), Sort By Name (Decreasing/Increasing)
// Sort By Weight, Sort By Power etc.
// And I want to start this menu by Sort_By
// Then the User will see the other options, it'll be a nice improvement but I might make me much time to do.

enum class Choose_Option {
    Add_Warship = 1,
    Add_Transporter,
    Show_The_Navy,               
    Sort_By,
    Count_Starships_Above_Power,
    Remove_Heavy_Starships,
    Calculate_The_Total_Power,
    Download_Fast_Starships,
    Export_Every_Starship_Name,
    Exit = 0
};     

enum class Sort_Option {
    By_Range = 1,
    By_Name,
    By_Weight,
    By_Drive_Unit,
    Go_Back = 5
};

enum class Sort_Option_By{
    Growing = 1,
    Descending,
    Go_Back = 3
};


class Menu
{
public:
    Menu() = default;
    ~Menu() = default;
    void wyswietlMenu() const;
    void uruchomMenu();

    void uruchomMenuSortowania();
    void wyswietlMenuSortowania() const;

    void addStatekBojowy();
    void addTransporter();
    void zliczStatkiPowyzejMocy();
    void usunCiezkieStatki();
    void pobierzSzybkieStatki();

    void by_range();
    void by_name();
    void by_weight();
    void by_drive_unit();

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
        {Choose_Option::Sort_By, [this] { 
            buff.clearScreen(); 
            uruchomMenuSortowania(); 
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


    std::unordered_map<Sort_Option, std::function<void()>> sortActions {
        {Sort_Option::By_Range, [this]{
            buff.clearScreen(); 
            by_range(); 
            buff.pressEnter(); 
        }},
        {Sort_Option::By_Name, [this]{
            buff.clearScreen(); 
            by_name(); 
            buff.pressEnter(); 
        }},
        {Sort_Option::By_Weight, [this]{
            buff.clearScreen(); 
            by_weight(); 
            buff.pressEnter(); 
        }},
        {Sort_Option::By_Drive_Unit, [this]{
            buff.clearScreen(); 
            by_drive_unit(); 
            buff.pressEnter(); 
        }},
        {Sort_Option::Go_Back, [this]{
            buff.clearScreen(); 
            buff.pressEnter(); 
        }}
    };

};
#endif // MENU_H