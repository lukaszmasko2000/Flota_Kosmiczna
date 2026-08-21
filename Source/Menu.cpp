#include "Menu.h"


//TODO TOMORROW
// Give some information when you choose the option. When you're printing "Starship navy", tell it.
// Later try to change switch case condition into something more modern (no in one day, but try prepare code for it)

void Menu::wyswietlMenu() const
{
    std::println("{:=^50}", " MENU GLOWNE ");
    std::print(
    R"( 
1. Dodaj statek bojowy
2. Dodaj transporter
3. Wyswietl flote
4. Sortuj po zasiegu
5. Zlicz statki powyzej mocy
6. Usun ciezkie statki
7. Oblicz calkowita moc floty
8. Pobierz szybkie statki
9. Eksport nazw wszystkich statkow
0. Wyjscie z programu
> )");
}

void Menu::uruchomMenu()
{
    auto wybor{0};
    Choose_Option option;

    do
    {
        wyswietlMenu();
        wybor = buff.getInt("Wybierz opcje: ");

        option = static_cast<Choose_Option>(wybor);

        auto it = actions.find(option);
        if (it != actions.end())
        {
            it->second();
        } else std::print("Nieprawidłowy wybór!\n");
       
    } while (option != Choose_Option::Exit);
}



void Menu::addStatekBojowy()
{
    auto nazwa { buff.getString("Podaj nazwe statku bojowego: ") };
    auto masa { buff.getInt("Podaj mase statku (w tonach): ") };
    auto mocNapedu { buff.getInt("Podaj moc napedu statku (w MW): ") };
    auto silaOgnia {buff.getInt("Podaj sile ognia statku: ")};

    flota.dodajStatek(std::make_unique<StatekBojowy>(nazwa, masa, mocNapedu, silaOgnia));
}
void Menu::addTransporter()
{
    auto nazwa {buff.getString("Podaj nazwe transportera: ")};
    auto masa{buff.getInt("Podaj mase transportera (w tonach): ")};
    auto mocNapedu{buff.getInt("Podaj moc napedu transportera (w MW): ")};
    auto przestrzen{buff.getInt("Podaj przestrzen transportera (w m^3): ")};

    flota.dodajStatek(std::make_unique<Transporter>(nazwa, masa, mocNapedu, przestrzen));
}
void Menu::zliczStatkiPowyzejMocy()
{
    auto moc {buff.getInt("Podaj moc do porownania: ")};
    std::print("Liczba statkow powyzej podanej mocy: {}\n",flota.zliczPowyzejMocy(moc));
}
void Menu::usunCiezkieStatki()
{    
    auto masa {buff.getInt("Podaj mase do usuniecia: ")};
    flota.usunCiezkie(masa);
}
void Menu::pobierzSzybkieStatki()
{
    auto predkosc {buff.getInt("Podaj predkosc do pobrania: ")};
    flota.pobierzSzybkieStatki(predkosc);
}