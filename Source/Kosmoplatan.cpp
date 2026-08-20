#include "Kosmoplatan.h"



void Kosmoplatan::wyswietl() const{
    // std::cout << "Statek: " << nazwa << " | Masa: " << masa 
    //               << "t | Moc: " << mocNapedu << "MW | Zasieg: " << obliczZasieg();
    std::print("Statek: {0}, Masa: {1}t, Moc: {2}MW | Zasięg: {3}", nazwa, masa, mocNapedu, obliczZasieg());
}