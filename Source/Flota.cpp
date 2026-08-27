#include "Flota.h"


/*----------------------------------------------------*/
/*--------------------FOR EACH------------------------*/
/*----------------------------------------------------*/

//Print All Records
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
void Flota::sortujPoZasiegu_Malejaco(){
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
void Flota::sortujPoMasie_Malejaco(){
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

//I will rewrite everything and make it easier xd
int Flota::zliczPowyzejMocy(int minMoc) const{
    return std::ranges::count_if(
        statki,
        [minMoc](const std::unique_ptr<Kosmoplatan>& ptr){
            return ptr->getMocNapedu() > minMoc;
        });
}

int Flota::zliczPonizejMocy(int maxMoc) const{
    return std::ranges::count_if(
        statki,
        [maxMoc](const std::unique_ptr<Kosmoplatan>& ptr){
            return ptr->getMocNapedu() < maxMoc;
        });
}
int Flota::zliczPowyzejMasy(int minMasa) const{
    return std::ranges::count_if(
        statki,
        [minMasa](const std::unique_ptr<Kosmoplatan>& ptr){
            return ptr->getMasa() > minMasa;
        });
}
int Flota::zliczPonizejMasy(int maxMasa) const{
    return std::ranges::count_if(
        statki,
        [maxMasa](const std::unique_ptr<Kosmoplatan>& ptr){
            return ptr->getMasa() < maxMasa;
        });
}
int Flota::zliczPowyzejZasiegu(int minZasieg) const{
    return std::ranges::count_if(
        statki,
        [minZasieg](const std::unique_ptr<Kosmoplatan>& ptr){
            return ptr->obliczZasieg() > minZasieg;
        });
}
int Flota::zliczPonizejZasiegu(int maxZasieg) const{
    return std::ranges::count_if(
        statki,
        [maxZasieg](const std::unique_ptr<Kosmoplatan>& ptr){
            return ptr->obliczZasieg() < maxZasieg;
        });
}


/*----------------------------------------------------*/


/*----------------------------------------------------*/
/*--------------------REMOVE IF-----------------------*/
/*----------------------------------------------------*/

//--------------------To remove later-------------------------
void Flota::usunCiezkie(int maxMasa){
    auto to_erase{
        std::ranges::remove_if(
            statki,
            [maxMasa](const std::unique_ptr<Kosmoplatan>& ptr) {
                return ptr && ptr->getMasa() > maxMasa;
            })};
    statki.erase(to_erase.begin(), to_erase.end());
}
//-------------------------------------------------------------

//Removing ships by weight in range
void Flota::usunPoMasie(int minMasa, int maxMasa){
    auto to_erase{
        std::ranges::remove_if(
            statki,
            [minMasa,maxMasa](const std::unique_ptr<Kosmoplatan>& ptr){
                return ptr && (ptr->getMasa() > minMasa) && (ptr->getMasa() < maxMasa);
            })};
}

//Removing ships by range in range
void Flota::usunPoZasiegu(int minZasieg,int maxZasieg){
    auto to_erase{
        std::ranges::remove_if(
            statki,
            [minZasieg,maxZasieg](const std::unique_ptr<Kosmoplatan>& ptr){
                return ptr && (ptr->obliczZasieg() > minZasieg) && (ptr->obliczZasieg() < maxZasieg);
            })};
    statki.erase(to_erase.begin(), to_erase.end());
}

//Removing ships by power in range
void Flota::usunPoMocy(int minMoc, int maxMoc){
    auto to_erase{
        std::ranges::remove_if(
            statki,
            [minMoc,maxMoc](const std::unique_ptr<Kosmoplatan>& ptr){
                return ptr && (ptr->getMocNapedu() > minMoc) && (ptr->getMocNapedu() < maxMoc);
            })};
    statki.erase(to_erase.begin(), to_erase.end());
}

//Removing ship by name
void Flota::usunPoNazwie(std::string nazwa){
    auto to_erase{
        std::ranges::remove_if(
            statki,
            [nazwa] (const std::unique_ptr<Kosmoplatan>& ptr){
                return ptr && ptr->getNazwa() == nazwa;
            }
        )};
    statki.erase(to_erase.begin(), to_erase.end());
}

/*----------------------------------------------------*/

/*----------------------------------------------------*/
/*-------------------ACCUMULATE-----------------------*/
/*----------------------------------------------------*/

//Adding all power
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

//Adding all weight
int Flota::obliczCalkowitaMase() const{
    return std::ranges::fold_left(
        statki,
        0,
        std::bind(
            std::plus<int>(),
            std::placeholders::_1,
            std::bind([](const std::unique_ptr<Kosmoplatan>& ptr) { 
                return ptr->getMasa(); 
            }, 
            std::placeholders::_2)
        )
    );
}

//Adding all range
int Flota::obliczCalkowityZasieg() const{
    return std::ranges::fold_left(
        statki,
        0,
        std::bind(
            std::plus<int>(),
            std::placeholders::_1,
            std::bind([](const std::unique_ptr<Kosmoplatan>& ptr) { 
                return ptr->obliczZasieg(); 
            }, 
            std::placeholders::_2)
        )
    );
}

/*----------------------------------------------------*/

/*----------------------------------------------------*/
/*-----------------------FILTER-----------------------*/
/*----------------------------------------------------*/

//--------------------To remove later-------------------------
void Flota::pobierzSzybkieStatki(double minZasieg){
    auto it_granica = std::ranges::partition(statki, [minZasieg](const std::unique_ptr<Kosmoplatan>& ptr) {
            return ptr->obliczZasieg() <= minZasieg;
        });

    std::ranges::for_each(it_granica, [](const std::unique_ptr<Kosmoplatan>& ptr) {
        std::print( " -> Szybki statek: {0}  (Zasięg: {1}) \n", ptr->getNazwa(), ptr->obliczZasieg());
        });
}
//-------------------------------------------------------------

//Print ships by the range of power
void Flota::pobierzStatkiPoMocy(double minMoc,double maxMoc) const{
    auto range = [minMoc, maxMoc](const std::unique_ptr<Kosmoplatan>& ptr) {
        return (ptr->getMocNapedu() >= minMoc) && (ptr->getMocNapedu() <= maxMoc);
    };

    for (const auto& statek : statki | std::views::filter(range)) {
        std::print(" -> Statki po Mocy: {} (Moc: {}) \n", 
                statek->getNazwa(), statek->getMocNapedu());
    }
}

//Print ships by the range of weight
void Flota::pobierzStatkiPoMasie(double minMasa,double maxMasa) const{
    auto range = [minMasa, maxMasa](const std::unique_ptr<Kosmoplatan>& ptr){
        return (ptr->getMasa() >= minMasa) && (ptr->getMasa() <= maxMasa);
    };

    for (const auto& statek : statki | std::views::filter(range))
        std::print(" -> Statki po Masie: {} (Masa: {}) \n",
                statek->getNazwa(), statek->getMasa());
        
}

//Print ships by the range of range
void Flota::pobierzStatkiPoZasiegu(double minZasieg,double maxZasieg) const{
    auto range = [minZasieg, maxZasieg](const std::unique_ptr<Kosmoplatan>& ptr){
        return (ptr->obliczZasieg() >= minZasieg) && (ptr->obliczZasieg() <= maxZasieg);
    };

    for (const auto& statek : statki | std::views::filter(range))
        std::print(" -> Statki po Zasiegu: {} (Masa: {}) \n", 
                statek->getNazwa(), statek->obliczZasieg());
}

//Print ships by the one number
void Flota::pobierzStatkiPoLiterce(char litera) const{
    auto matchChar = [litera](const std::unique_ptr<Kosmoplatan>& ptr) {
        auto nazwa = ptr->getNazwa();
        return !nazwa.empty() && nazwa[0] == litera;
    };

    for (const auto& statek : statki | std::views::filter(matchChar)) {
        std::print(" -> Statek na litere '{}': {} \n", 
                   litera, statek->getNazwa());
    }
}

/*----------------------------------------------------*/

/*----------------------------------------------------*/
/*------------------TRANSFORM-------------------------*/
/*----------------------------------------------------*/

//Export ships names
void Flota::eksportujNazwy() const{
    std::ranges::transform(
            statki,
            std::ostream_iterator<std::string>(std::cout, "\n"),
            [](const std::unique_ptr<Kosmoplatan>& ptr) { return ptr->getNazwa(); }
        );
}

//Export ships power
void Flota::eksportujMoc() const{
    std::ranges::transform(
            statki,
            std::ostream_iterator<int>(std::cout, "\n"),
            [](const std::unique_ptr<Kosmoplatan>& ptr) { return ptr->getMocNapedu(); }
    );
}

//Export ships range
void Flota::eksportujZasieg() const{
    std::ranges::transform(
        statki,
        std::ostream_iterator<int>(std::cout, "\n"),
        [](const std::unique_ptr<Kosmoplatan>& ptr) { return ptr->obliczZasieg(); }
    );
}

//Export ships weight
void Flota::eksportujMase() const{
    std::ranges::transform(
        statki,
        std::ostream_iterator<int>(std::cout, "\n"),
        [](const std::unique_ptr<Kosmoplatan>& ptr) { return ptr->getMasa(); }
    );
}

/*----------------------------------------------------*/