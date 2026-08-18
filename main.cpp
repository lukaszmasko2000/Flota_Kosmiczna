#include <iostream>

#include "Kosmoplatan.h"
#include "Transporter.h"
#include "StatekBojowy.h"
#include "Flota.h"

int main() {
     std::cout << "=== TEST ROZPOCZETY (Alokacja obiektow) ===" << std::endl;
    
    // Blok ograniczający czas życia floty, w celu weryfikacji automatycznego czyszczenia pamięci
    {
        Flota flota;

        // Dynamiczna alokacja elementów przez surowe wskaźniki
        flota.dodajStatek(new StatekBojowy("X-Wing", 15, 500, 5));      
        flota.dodajStatek(new Transporter("Cargomaster", 120, 800, 80)); 
        flota.dodajStatek(new StatekBojowy("Niszczyciel", 450, 2500, 50)); 
        flota.dodajStatek(new Transporter("Shuttle-T4", 45, 400, 20));    

        std::cout << "\n--- Stan Floty Poczatkowy ---" << std::endl;
        flota.wyswietlFlote();

        std::cout << "\n--- Sortowanie po zasiegu (Malejaco) ---" << std::endl;
        flota.sortujPoZasiegu();
        flota.wyswietlFlote();

        std::cout << "\n--- Test zliczania (Moc > 600 MW) ---" << std::endl;
        std::cout << "Liczba statkow: " << flota.zliczPowyzejMocy(600) << " (Oczekiwano: 2)" << std::endl;

        std::cout << "\n--- Test sumowania mocy (std::plus + std::bind) ---" << std::endl;
        std::cout << "Calkowita moc floty: " << flota.obliczCalkowitaMoc() << " MW (Oczekiwano: 4200 MW)" << std::endl;

        std::cout << "\n--- Test adaptera back_inserter (Statki z zasiegiem >= 1000) ---" << std::endl;
        std::vector<Kosmoplatan*> szybkaFlota;
        flota.pobierzSzybkieStatki(szybkaFlota, 1000.0);
        
        std::for_each(szybkaFlota.begin(), szybkaFlota.end(), [](const Kosmoplatan* s) {
            if (s) std::cout << " -> Szybki statek: " << s->getNazwa() << " (Zasieg: " << s->obliczZasieg() << ")\n";
        });

        std::cout << "\n--- Eksport nazw wszystkich statkow (ostream_iterator) ---" << std::endl;
        flota.eksportujNazwy();

        std::cout << "\n--- Usuniecie statkow ciezszych niz 100t ---" << std::endl;
        // Metoda powinna usunąć z pamięci i wywołać destruktory dla: Cargomaster oraz Niszczyciel
        flota.usunCiezkie(100); 
        
        std::cout << "\n--- Stan Floty po usunieciu ---" << std::endl;
        flota.wyswietlFlote();
        
        std::cout << "\n=== Koniec bloku lokalnego (Flota zaraz opusci zasieg) ===" << std::endl;
    } // <- Tutaj destruktor floty usuwa pozostałe statki: X-Wing oraz Shuttle-T4.
    
    std::cout << "\n=== TEST ZAKONCZONY ===" << std::endl;
    std::cout << "Weryfikacja: Odnotowanie na ekranie dokladnie 4 komunikatów [Destruktor] oznacza brak wyciekow." << std::endl;

    return 0;
}