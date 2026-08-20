#include <iostream>

#include "Kosmoplatan.h"
#include "Transporter.h"
#include "StatekBojowy.h"
#include "Flota.h"
#include "Menu.h"

int main() {

    
    Menu menu;
    menu.uruchomMenu();
    
    std::cout << "\nNacisnij Enter, aby kontynuowac...";
    std::cin.ignore(); 
    std::cin.get();

    return 0;
}