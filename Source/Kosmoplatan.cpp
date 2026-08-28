#include "Kosmoplatan.h"



void Kosmoplatan::wyswietl() const{
    std::print("| {:<14} | {:>4}t | {:>6}MW | {:>8.2f} | ", nazwa, masa, mocNapedu, obliczZasieg());
}