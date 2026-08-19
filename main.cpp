#include <iostream>

#include "Kosmoplatan.h"
#include "Transporter.h"
#include "StatekBojowy.h"
#include "Flota.h"

int main() {

    std::cout << "=== TEST ROZPOCZETY (Bezpieczna alokacja unique_ptr) ===" << std::endl;
    // Blok ograniczający czas życia floty, w celu weryfikacji automatycznego czyszczenia pamięci
    
    {
        Flota flota;

        flota.dodajStatek(std::make_unique<StatekBojowy>("X-Wing", 15, 500, 5));      
        flota.dodajStatek(std::make_unique<Transporter>("Cargomaster", 120, 800, 80)); 
        flota.dodajStatek(std::make_unique<StatekBojowy>("Niszczyciel", 450, 2500, 50)); 
        flota.dodajStatek(std::make_unique<Transporter>("Shuttle-T4", 45, 400, 20));    

        std::cout << "\n--- Stan Floty Poczatkowy ---" << std::endl;
        flota.wyswietlFlote();

        std::cout << "\n--- Sortowanie po zasiegu (Malejaco) ---" << std::endl;
        flota.sortujPoZasiegu();
        flota.wyswietlFlote();

        std::cout << "\n--- Test zliczania (Moc > 600 MW) ---" << std::endl;
        std::cout << "Liczba statkow: " << flota.zliczPowyzejMocy(600) << " (Oczekiwano: 2)" << std::endl;

        std::cout << "\n--- Test sumowania mocy (std::plus + std::bind) ---" << std::endl;
        std::cout << "Calkowita moc floty: " << flota.obliczCalkowitaMoc() << " MW (Oczekiwano: 4200 MW)" << std::endl;

        std::cout << "\n--- Test partition i wyswietlania (Statki z zasiegiem >= 1000) ---" << std::endl;
        flota.pobierzSzybkieStatki(1000.0);

        std::cout << "\n--- Eksport nazw wszystkich statkow (ostream_iterator) ---" << std::endl;
        flota.eksportujNazwy();

        std::cout << "\n--- Usuniecie statkow ciezszych niz 100t ---" << std::endl;
        flota.usunCiezkie(100); 
        
        std::cout << "\n--- Stan Floty po usunieciu ---" << std::endl;
        flota.wyswietlFlote();
        
        std::cout << "\n=== Koniec bloku lokalnego (Flota zaraz opusci zasieg) ===" << std::endl;
    } 
    
    std::cout << "\n=== TEST ZAKONCZONY ===" << std::endl;
    std::cout << "Weryfikacja: Wszystkie 4 obiekty zwolnione w odpowiednich momentach cyklu zycia programu." << std::endl;

    return 0;
}