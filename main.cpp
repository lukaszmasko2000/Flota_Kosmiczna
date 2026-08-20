#include <iostream>

#include "Kosmoplatan.h"
#include "CinBuf.h"
#include "Transporter.h"
#include "StatekBojowy.h"
#include "Flota.h"
#include "Menu.h"

int main() {

    CinBuf buff;
    {
        Menu menu;
        menu.uruchomMenu();
    }
    buff.pressEnter();

    return 0;
}