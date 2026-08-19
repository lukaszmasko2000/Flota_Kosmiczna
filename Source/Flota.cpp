#include "Flota.h"



void Flota::wyswietlFlote() const{
    std::for_each(statki.begin(), statki.end(), [](const std::unique_ptr<Kosmoplatan>& ptr){ ptr->wyswietl(); });
}
void Flota::sortujPoZasiegu(){
     std::sort(
         statki.begin(), 
         statki.end(), 
         [](const std::unique_ptr<Kosmoplatan>& ptr1, const std::unique_ptr<Kosmoplatan>& ptr2){
             return ptr1->obliczZasieg() > ptr2->obliczZasieg();            
        });
}
int Flota::zliczPowyzejMocy(int minMoc) const{
    auto moc{
        std::count_if(
            statki.begin(),
            statki.end(),
            [minMoc](const std::unique_ptr<Kosmoplatan>& ptr){
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
            [maxMasa](const std::unique_ptr<Kosmoplatan>& ptr) {
                return ptr && ptr->getMasa() > maxMasa;
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
                std::bind([](const std::unique_ptr<Kosmoplatan>& ptr) {return ptr->getMocNapedu();}, std::placeholders::_2)
            )
        )
    };
    return sum;
}
void Flota::pobierzSzybkieStatki(double minZasieg) const{
    auto it_granica{
        std::stable_partition(
            statki.begin(),
            statki.end(),
            [minZasieg](std::unique_ptr<Kosmoplatan>& ptr){
                return ptr->obliczZasieg() > minZasieg;
            })};
    std::for_each(
        statki.begin(),
        it_granica,
        [](std::unique_ptr<Kosmoplatan>& ptr){
            std::cout << " -> Szybki statek: " << ptr->getNazwa() << " (Zasieg: " << ptr->obliczZasieg() << ")\n";
        }
    );
}
void Flota::eksportujNazwy() const{
    std::transform(
            statki.begin(),
            statki.end(),
            std::ostream_iterator<std::string>(std::cout, "\n"),
            [](const std::unique_ptr<Kosmoplatan>& ptr) { return ptr->getNazwa(); }
        );
}
