
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