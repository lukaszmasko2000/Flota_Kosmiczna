#include "Flota.h"



void Flota::wyswietlFlote() const{
    std::ranges::for_each(
        std::as_const(statki), 
        [](const std::unique_ptr<Kosmoplatan>& ptr) { 
            ptr->wyswietl(); 
        });
}
void Flota::sortujPoZasiegu(){
        std::ranges::sort(
            statki,
            [](const std::unique_ptr<Kosmoplatan>& ptr1, const std::unique_ptr<Kosmoplatan>& ptr2){
             return ptr1->obliczZasieg() > ptr2->obliczZasieg();
            });
}
int Flota::zliczPowyzejMocy(int minMoc) const{
    return std::ranges::count_if(
        statki,
        [minMoc](const std::unique_ptr<Kosmoplatan>& ptr){
            return ptr->getMocNapedu() > minMoc;
        });
}
void Flota::usunCiezkie(int maxMasa){
    auto to_erase{
        std::ranges::remove_if(
            statki,
            [maxMasa](const std::unique_ptr<Kosmoplatan>& ptr) {
                return ptr && ptr->getMasa() > maxMasa;
            })};
    statki.erase(to_erase.begin(), to_erase.end());
}
int Flota::obliczCalkowitaMoc() const{
   return std::ranges::fold_left(
        statki,
        0,
        std::bind(
            std::plus<int>(),
            std::placeholders::_1,
            std::bind([](const std::unique_ptr<Kosmoplatan>& ptr) { 
                return ptr->getMocNapedu(); 
            }, 
            std::placeholders::_2)
        )
    );
}
void Flota::pobierzSzybkieStatki(double minZasieg){
    auto it_granica = std::ranges::partition(statki, [minZasieg](const std::unique_ptr<Kosmoplatan>& ptr) {
            return ptr->obliczZasieg() <= minZasieg;
        });

    std::ranges::for_each(it_granica, [](const std::unique_ptr<Kosmoplatan>& ptr) {
        std::cout << " -> Szybki statek: "
            << ptr->getNazwa()
            << " (Zasieg: " << ptr->obliczZasieg() << ")\n";
        });
}
void Flota::eksportujNazwy() const{
    std::ranges::transform(
            statki,
            std::ostream_iterator<std::string>(std::cout, "\n"),
            [](const std::unique_ptr<Kosmoplatan>& ptr) { return ptr->getNazwa(); }
        );
}
