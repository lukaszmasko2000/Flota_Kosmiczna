#include "Menu.h"


//TODO TOMMOROW
//Make the menu more cool and useful.
//Also make the code more safer for users. For example for now I can give string value into int. Prevent it.


void Menu::wyswietlMenu() const
{
    std::println("{:=^50}", " MENU GLOWNE ");
    std::print(
    R"( 
1. Dodaj statek bojowy
2. Dodaj transporter
3. Sortuj po zasiegu
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
    do
    {
        wyswietlMenu();
        wybor = buff.getInt("Wybierz opcje: ");

        switch (wybor)
        {
            case 1:
                buff.clearScreen();
                addStatekBojowy();
                buff.pressEnter();
                break;
            case 2:
                buff.clearScreen();
                addTransporter();
                buff.pressEnter();
                break;
            case 3:
                buff.clearScreen();
                flota.wyswietlFlote();
                buff.pressEnter();
                break;
            case 4:
                buff.clearScreen();
                flota.sortujPoZasiegu();
                buff.pressEnter();
                break;
            case 5:
                buff.clearScreen();
                zliczStatkiPowyzejMocy();
                buff.pressEnter();
                break;
            case 6:
                buff.clearScreen();
                usunCiezkieStatki();
                buff.pressEnter();
                break;
            case 7:
                buff.clearScreen();
                std::cout << "Calkowita moc floty: " << flota.obliczCalkowitaMoc() << " MW" << std::endl;
                buff.pressEnter();
                break;
            case 8:
                buff.clearScreen();
                pobierzSzybkieStatki();
                buff.pressEnter();
                break;
            case 9:
                buff.clearScreen();
                flota.eksportujNazwy();
                buff.pressEnter();
                break;
            case 0:
                buff.clearScreen();
                std::cout << "Wyjscie z programu." << std::endl;
                buff.pressEnter();
                break;
            default:
                buff.clearScreen();
                std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
                buff.pressEnter();
        }
    } while (wybor != 0);
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
    std::cout << "Liczba statkow powyzej podanej mocy: " << flota.zliczPowyzejMocy(moc) << std::endl;
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