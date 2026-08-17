#include "StatekBojowy.h"



double StatekBojowy::obliczZasieg() const{
    auto oblicz{static_cast<double>((getMocNapedu() * 100) / (getMasa() + silaOgnia))};
    return oblicz;
}
void StatekBojowy::wyswietl() const{
    
}