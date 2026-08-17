#include "Kosmoplatan.h"



void Kosmoplatan::wyswietl() const{
    std::cout << "Statek: " << nazwa << " | Masa: " << masa 
                  << "t | Moc: " << mocNapedu << "MW | Zasieg: " << obliczZasieg();
}