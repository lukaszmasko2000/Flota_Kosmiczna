#include "Transporter.h"


double Transporter::obliczZasieg() const
{
    auto oblicz{static_cast<double>((static_cast<double>(getMocNapedu()) * 150) / (getMasa() + ladownosc * 0.5))};
    return oblicz;
}
void Transporter::wyswietl() const
{
    Kosmoplatan::wyswietl();
    // std::cout << " | [Transporter] Ladownosc: " << ladownosc << "t" << std::endl;
    std::print(" | [Transporter] Ladownosc: {0}t\n", ladownosc);
}
