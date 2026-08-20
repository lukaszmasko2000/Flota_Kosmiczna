#include "StatekBojowy.h"



double StatekBojowy::obliczZasieg() const{
    auto oblicz{static_cast<double>((getMocNapedu() * 100) / (getMasa() + silaOgnia))};
    return oblicz;
}
void StatekBojowy::wyswietl() const{
    Kosmoplatan::wyswietl();
    // std::cout << " | [Bojowy] Sila ognia: " << silaOgnia << std::endl;
    std::print(" | [Bojowy] Sila ognia: {}\n", silaOgnia);
}