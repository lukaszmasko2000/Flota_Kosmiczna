#include "Kosmoplatan.h"



void Kosmoplatan::wyswietl() const{
    std::print("Statek: {0}, Masa: {1}t, Moc: {2}MW | Zasięg: {3}", nazwa, masa, mocNapedu, obliczZasieg());
}