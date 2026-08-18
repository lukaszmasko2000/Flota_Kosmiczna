#include "Flota.h"


//TODO TOMMOROW

void Flota::wyswietlFlote() const{
    std::for_each(statki.begin(), statki.end(), [](const Kosmoplatan* ptr){ ptr->wyswietl(); });
}
void Flota::sortujPoZasiegu(){
     std::sort(
         statki.begin(), 
         statki.end(), 
         [](const Kosmoplatan* ptr1, const Kosmoplatan* ptr2){
             return ptr1->obliczZasieg() > ptr2->obliczZasieg();            
        });
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
    statki.erase(
        std::remove_if(
            statki.begin(),
            statki.end(),
            [maxMasa](const Kosmoplatan* ptr) {
                if (ptr && ptr->getMasa() > maxMasa){
                    delete ptr; return true;
                }
                return false;
            }),statki.end());
}
int Flota::obliczCalkowitaMoc() const{
    auto sum{
        std::accumulate(
            statki.begin(),
            statki.end(),
            0,
            std::bind(
                std::plus<int>(),
                std::placeholders::_1,
                std::bind([](const Kosmoplatan* ptr) {return ptr->getMocNapedu();}, std::placeholders::_2)
            )
        )
    };
    return sum;
}
void Flota::pobierzSzybkieStatki(std::vector<Kosmoplatan*>& cel, double minZasieg) const{

}
void Flota::eksportujNazwy() const{

}