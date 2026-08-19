
#include "Menu.h"


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
                // Dodaj statek bojowy
                break;
            case 2:
                // Dodaj transporter
                break;
            case 3:
                flota.wyswietlFlote();
                break;
            case 4:
                flota.sortujPoZasiegu();
                break;
            case 5:
                // Zlicz statki powyzej mocy
                break;
            case 6:
                // Usun ciezkie statki
                break;
            case 7:
                std::cout << "Calkowita moc floty: " << flota.obliczCalkowitaMoc() << " MW" << std::endl;
                break;
            case 8:
                // Pobierz szybkie statki
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