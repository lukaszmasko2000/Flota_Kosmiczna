#include <iostream>

#include "CinBuf.h"
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