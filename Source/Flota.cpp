#include "Flota.h"


/*----------------------------------------------------*/
/*--------------------SHOW--------------------------*/
/*----------------------------------------------------*/

void Flota::wyswietlFlote() const{
    std::ranges::for_each(
        std::as_const(statki), 
        [](const std::unique_ptr<Kosmoplatan>& ptr) { 
            ptr->wyswietl(); 
        });
}

/*----------------------------------------------------*/




/*----------------------------------------------------*/
/*--------------------SORT BY-------------------------*/
/*----------------------------------------------------*/

// From Lower to Higher
void Flota::sortujPoZasiegu_Rosnaco(){
    std::ranges::sort(
            statki,
            [](const std::unique_ptr<Kosmoplatan>& ptr1, const std::unique_ptr<Kosmoplatan>& ptr2){
             return ptr1->obliczZasieg() < ptr2->obliczZasieg();
            });
}

// From Higher to Lower
void Flota::sortujPoZasiegu(){
        std::ranges::sort(
            statki,
            [](const std::unique_ptr<Kosmoplatan>& ptr1, const std::unique_ptr<Kosmoplatan>& ptr2){
             return ptr1->obliczZasieg() > ptr2->obliczZasieg();
            });
}

// From Lower to Higher
void Flota::sortujPoMasie_Rosnaco(){
    std::ranges::sort(
            statki,
            [](const std::unique_ptr<Kosmoplatan>& ptr1, const std::unique_ptr<Kosmoplatan>& ptr2){
             return ptr1->getMasa() < ptr2->getMasa();
            });
}

// From Higher to Lower
void Flota::sorturPoMasie_Malejaco(){
    std::ranges::sort(
            statki,
            [](const std::unique_ptr<Kosmoplatan>& ptr1, const std::unique_ptr<Kosmoplatan>& ptr2){
             return ptr1->getMasa() > ptr2->getMasa();
            });
}

// From Lower to Higher
void Flota::sortujPoNazwie_Rosnaco(){
    std::ranges::sort(
            statki,
            [](const std::unique_ptr<Kosmoplatan>& ptr1, const std::unique_ptr<Kosmoplatan>& ptr2){
             return ptr1->getNazwa() < ptr2->getNazwa();
            });
}

// From Higher to Lower
void Flota::sortujPoNazwie_Malejaco(){
    std::ranges::sort(
            statki,
            [](const std::unique_ptr<Kosmoplatan>& ptr1, const std::unique_ptr<Kosmoplatan>& ptr2){
             return ptr1->getNazwa() > ptr2->getNazwa();
            });
}

// From Lower to Higher
void Flota::sortujPoMocyNapedu_Rosnaco(){
    std::ranges::sort(
            statki,
            [](const std::unique_ptr<Kosmoplatan>& ptr1, const std::unique_ptr<Kosmoplatan>& ptr2){
             return ptr1->getMocNapedu() < ptr2->getMocNapedu();
            });
}

// From Higher to Lower
void Flota::sortujPoMocyNapedu_Malejaco(){
    std::ranges::sort(
            statki,
            [](const std::unique_ptr<Kosmoplatan>& ptr1, const std::unique_ptr<Kosmoplatan>& ptr2){
             return ptr1->getMocNapedu() > ptr2->getMocNapedu();
            });
}


/*----------------------------------------------------*/


/*----------------------------------------------------*/
/*--------------------COUNT IF------------------------*/
/*----------------------------------------------------*/


int Flota::zliczPowyzejMocy(int minMoc) const{
    return std::ranges::count_if(
        statki,
        [minMoc](const std::unique_ptr<Kosmoplatan>& ptr){
            return ptr->getMocNapedu() > minMoc;
        });
}


/*----------------------------------------------------*/
/*--------------------REMOVE IF-----------------------*/
/*----------------------------------------------------*/

void Flota::usunCiezkie(int maxMasa){
    auto to_erase{
        std::ranges::remove_if(
            statki,
            [maxMasa](const std::unique_ptr<Kosmoplatan>& ptr) {
                return ptr && ptr->getMasa() > maxMasa;
            })};
    statki.erase(to_erase.begin(), to_erase.end());
}


/*----------------------------------------------------*/
/*-------------------ACCUMULATE-----------------------*/
/*----------------------------------------------------*/

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

/*----------------------------------------------------*/
/*--------------------SHOW IF-------------------------*/
/*----------------------------------------------------*/


void Flota::pobierzSzybkieStatki(double minZasieg){
    auto it_granica = std::ranges::partition(statki, [minZasieg](const std::unique_ptr<Kosmoplatan>& ptr) {
            return ptr->obliczZasieg() <= minZasieg;
        });

    std::ranges::for_each(it_granica, [](const std::unique_ptr<Kosmoplatan>& ptr) {
        std::print( " -> Szybki statek: {0}  (Zasięg: {1}) \n", ptr->getNazwa(), ptr->obliczZasieg());
        });
}


/*----------------------------------------------------*/
/*------------------TRANSFORM-------------------------*/
/*----------------------------------------------------*/


void Flota::eksportujNazwy() const{
    std::ranges::transform(
            statki,
            std::ostream_iterator<std::string>(std::cout, "\n"),
            [](const std::unique_ptr<Kosmoplatan>& ptr) { return ptr->getNazwa(); }
        );
}
