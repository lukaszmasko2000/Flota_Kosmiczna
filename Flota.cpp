#include "Flota.h"


//TODO TOMMOROW

void Flota::wyswietlFlote() const{
    std::for_each(statki.begin(), statki.end(), [](const Kosmoplatan* ptr){ ptr->wyswietl(); });
}
void Flota::sortujPoZasiegu() const{
    // std::sort(
    //     statki.begin(), 
    //     statki.end(), 
    //     [](Kosmoplatan* ptr1, Kosmoplatan* ptr2){
    //         return ptr1->obliczZasieg() > ptr2->obliczZasieg();            
    //     });
}
int Flota::zliczPowyzejMocy(int minMoc) const{
    auto moc{
        std::count_if(
            statki.begin(),
            statki.end(),
            [minMoc](const Kosmoplatan* ptr){
                return ptr->getMocNapedu() > minMoc;
            })
    };
    
    return moc;
}
void Flota::usunCiezkie(int maxMasa){

}
int Flota::obliczCalkowitaMoc() const{

}
void Flota::pobierzSzybkieStatki(std::vector<Kosmoplatan*>& cel, double minZasieg) const{

}
void Flota::eksportujNazwy() const{

}