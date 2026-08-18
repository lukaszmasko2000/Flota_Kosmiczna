#include "Flota.h"


//TODO TOMMOROW

void Flota::wyswietlFlote() const{
    std::for_each(statki.begin(), statki.end(), [](const Kosmoplatan* ptr){ ptr->wyswietl(); });
}
void Flota::sortujPoZasiegu() const{

}
int Flota::zliczPowyzejMocy(int minMoc) const{

}
void Flota::usunCiezkie(int maxMasa){

}
int Flota::obliczCalkowitaMoc() const{

}
void Flota::pobierzSzybkieStatki(std::vector<Kosmoplatan*>& cel, double minZasieg) const{

}
void Flota::eksportujNazwy() const{

}