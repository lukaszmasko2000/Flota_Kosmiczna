
#include "Menu.h"


//TODO TOMMOROW
//Make the menu more cool and useful.
//Also make the code more safer for users. For example for now I can give string value into int. Prevent it.


void Menu::wyswietlMenu() const
{
    std::cout << std::setfill('=') << std::setw(50) << "" << std::endl;
    std::cout << "=== MENU GLOWNE ===" << std::endl;
    std::cout << std::setfill('=') << std::setw(50) << "" << std::endl;
    std::cout << "1. Dodaj statek bojowy" << std::endl;
    std::cout << "2. Dodaj transporter" << std::endl;
    std::cout << "3. Wyswietl flote" << std::endl;
    std::cout << "4. Sortuj po zasiegu" << std::endl
              << "5. Zlicz statki powyzej mocy" << std::endl
              << "6. Usun ciezkie statki" << std::endl
              << "7. Oblicz calkowita moc floty" << std::endl
              << "8. Pobierz szybkie statki" << std::endl
              << "9. Eksport nazw wszystkich statkow" << std::endl
              << "0. Wyjscie z programu" << std::endl;
}

void Menu::uruchomMenu()
{
    int wybor;
    do
    {
        wyswietlMenu();
        std::cout << "Wybierz opcje: ";
        std::cin >> wybor;

        switch (wybor)
        {
            case 1:
                addStatekBojowy();
                break;
            case 2:
                addTransporter();
                break;
            case 3:
                flota.wyswietlFlote();
                std::cout << "\nNacisnij Enter, aby kontynuowac...";
                std::cin.ignore(); // This throws away the leftover 'Enter' from your menu choice
                std::cin.get();    // This actually pauses and waits for you to press Enter
                break;
            case 4:
                flota.sortujPoZasiegu();
                break;
            case 5:
                zliczStatkiPowyzejMocy();
                break;
            case 6:
                usunCiezkieStatki();
                break;
            case 7:
                std::cout << "Calkowita moc floty: " << flota.obliczCalkowitaMoc() << " MW" << std::endl;
                break;
            case 8:
                pobierzSzybkieStatki();
                break;
            case 9:
                flota.eksportujNazwy();
                break;
            case 0:
                std::cout << "Wyjscie z programu." << std::endl;
                break;
            default:
                std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
        }
    } while (wybor != 0);
}



void Menu::addStatekBojowy()
{
    std::string nazwa;
    int masa, mocNapedu, silaOgnia;

    std::cout << "Podaj nazwe statku bojowego: ";
    std::cin >> nazwa;
    std::cout << "Podaj mase statku (w tonach): ";
    std::cin >> masa;
    std::cout << "Podaj moc napedu statku (w MW): ";
    std::cin >> mocNapedu;
    std::cout << "Podaj sile ognia statku: ";
    std::cin >> silaOgnia;

    flota.dodajStatek(std::make_unique<StatekBojowy>(nazwa, masa, mocNapedu, silaOgnia));
}
void Menu::addTransporter()
{
    std::string nazwa;
    int masa, mocNapedu, przestrzen;

    std::cout << "Podaj nazwe transportera: ";
    std::cin >> nazwa;
    std::cout << "Podaj mase transportera (w tonach): ";
    std::cin >> masa;
    std::cout << "Podaj moc napedu transportera (w MW): ";
    std::cin >> mocNapedu;
    std::cout << "Podaj przestrzen transportera (w m^3): ";
    std::cin >> przestrzen;

    flota.dodajStatek(std::make_unique<Transporter>(nazwa, masa, mocNapedu, przestrzen));
}
void Menu::zliczStatkiPowyzejMocy()
{
    int moc;
    std::cout << "Podaj moc do porownania: ";
    std::cin >> moc;
    std::cout << "Liczba statkow powyzej podanej mocy: " << flota.zliczPowyzejMocy(moc) << std::endl;
}
void Menu::usunCiezkieStatki()
{
    int masa;
    std::cout << "Podaj mase do usuniecia: ";
    std::cin >> masa;
    flota.usunCiezkie(masa);
}
void Menu::pobierzSzybkieStatki()
{
    int predkosc;
    std::cout << "Podaj predkosc do pobrania: ";
    std::cin >> predkosc;
    flota.pobierzSzybkieStatki(predkosc);
}