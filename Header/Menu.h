#ifndef MENU_H
#define MENU_H


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

private:
    Flota flota;

};
#endif // MENU_H