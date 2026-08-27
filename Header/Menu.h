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


//TODO Tommorow
// Add more option at the menu.
// For Example if there's a option about removing some functions depending by value then add more.
// Or count starships above.... , Calculate the total... , Download ... (Slowest, Fastes etc)
// Export something diffrent than only Name.

//And lately I will make saving. I mean I want to save the date into file with writing. Like it's doing in games.
//That's my next challenge to do.

//Also I can partition the menu class. I mean I can make more .cpp files If It needed.

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
    Go_Back = 0
};

enum class Sort_Option_By{
    Growing = 1,
    Descending,
    Go_Back = 0
};


enum class Count_If_Option {
    By_Power = 1,
    By_Weight,
    By_Range,
    Go_Back = 0
};
enum class Remove_If_Option {
    By_Power = 1,
    By_Weight,
    By_Range,
    Go_Back = 0
};
enum class Fold_Left_Option {
    By_Range = 1,
    By_Drive_Unit,
    By_Weight,
    Go_Back = 0
};
enum class Filter_Option {
    By_Power = 1,
    By_Weight,
    By_Range,
    By_Name,
    Go_Back = 0
};
enum class Transform_Option {
    By_Power = 1,
    By_Weight,
    By_Range,
    By_Name,
    Go_Back = 0
};

// template <class T>
// void uruchomMenuSortowaniaPo();


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

    void wyswietlMenuSortowaniaPo() const;
    void by_range();
    void by_name();
    void by_weight();
    void by_drive_unit();

    void wyswietlMenuZliczStatki() const;
    void wyswietlMenuUsun() const;
    void wyswietlMenuOblicz() const;
    void wyswietlMenuPobierzStatki() const;
    void wyswietlMenuEksortuj() const;

    void uruchomMenuZliczStatki();
    void uruchomMenuUsun();
    void uruchomMenuOblicz();
    void uruchomMenuPobierzStatki();
    void uruchomMenuEksportuj();

private:
    Flota flota;
    CinBuf buff;

    /*------------------------------------MAIN MENU-----------------------------------------*/
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
            //buff.pressEnter(); 
        }}
    };
    /*-------------------------------------------------------------------------------*/

    /*----------------------------SORTING SUB-MENU-----------------------------------*/
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
            //buff.pressEnter(); 
        }}
    };
    /*-------------------------------------------------------------------------------*/

    /*--------------------------------SORTING SUB------------------------------------*/
    std::unordered_map<Sort_Option_By, std::function<void()>> sortActionsByRange{
        {Sort_Option_By::Growing, [this]{
            buff.clearScreen();
            flota.sortujPoZasiegu_Rosnaco();
        }},
        {Sort_Option_By::Descending, [this]{
            buff.clearScreen();
            flota.sortujPoZasiegu_Malejaco();
        }},
        {Sort_Option_By::Go_Back, [this]{
            buff.clearScreen();
        }}
    };
    std::unordered_map<Sort_Option_By, std::function<void()>> sortActionsByName{
        {Sort_Option_By::Growing, [this]{
            buff.clearScreen();
            flota.sortujPoNazwie_Rosnaco();
        }},
        {Sort_Option_By::Descending, [this]{
            buff.clearScreen();
            flota.sortujPoNazwie_Malejaco();
        }},
        {Sort_Option_By::Go_Back, [this]{
            buff.clearScreen();
        }}
    };
    std::unordered_map<Sort_Option_By, std::function<void()>> sortActionsByWeight{
        {Sort_Option_By::Growing, [this]{
            buff.clearScreen();
            flota.sortujPoMasie_Rosnaco();
        }},
        {Sort_Option_By::Descending, [this]{
            buff.clearScreen();
            flota.sortujPoMasie_Malejaco();
        }},
        {Sort_Option_By::Go_Back, [this]{
            buff.clearScreen();
        }}
    };
    std::unordered_map<Sort_Option_By, std::function<void()>> sortActionsByDriveUnit{
        {Sort_Option_By::Growing, [this]{
            buff.clearScreen();
            flota.sortujPoMocyNapedu_Rosnaco();
        }},
        {Sort_Option_By::Descending, [this]{
            buff.clearScreen();
            flota.sortujPoMocyNapedu_Malejaco();
        }},
        {Sort_Option_By::Go_Back, [this]{
            buff.clearScreen();
        }}
    };
    /*-------------------------------------------------------------------------------*/
    /*------------------------------------MENU COUNT SHIPS-----------------------------------------*/
    std::unordered_map<Count_If_Option,std::function<void()>> countIfActions{};
    /*---------------------------------------------------------------------------------------------*/
    /*------------------------------------MENU REMOVE SHIPS-----------------------------------------*/
    std::unordered_map<Remove_If_Option,std::function<void()>> removeIfActions{};
    /*----------------------------------------------------------------------------------------------*/
    /*------------------------------------MENU ACCUMULATE SHIPS-------------------------------------*/
    std::unordered_map<Fold_Left_Option,std::function<void()>> foldLeftActions{};
    /*------------------------------------------------------------------------------------------------*/
    /*------------------------------------MENU FILTER-----------------------------------------*/
    std::unordered_map<Filter_Option,std::function<void()>> filterActions{};
    /*----------------------------------------------------------------------------------------*/
    /*---------------------------------MENU TRANSFORM-----------------------------------------*/
    std::unordered_map<Transform_Option,std::function<void()>> transformActions{};
    /*----------------------------------------------------------------------------------------*/
};
#endif // MENU_H