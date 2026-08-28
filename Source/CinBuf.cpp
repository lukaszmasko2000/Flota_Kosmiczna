#include "CinBuf.h"



void CinBuf::pressEnter() const
{
    std::print("\nNacisnij Enter, aby kontynuowac...");
    std::fflush(stdout);

    std::cin.get();

    std::print("\033[2J\033[1;1H");
    std::fflush(stdout);
}


int CinBuf::getInt(std::string_view prompt) {
    int temp{0};

    while (true) {
        std::print("{}", prompt);
        std::fflush(stdout); 

        if (std::cin >> temp) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return temp;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::println("Blad: Nieprawidlowy znak. Wprowadz liczbe!");
    }
}

std::string CinBuf::getString(std::string_view prompt)
{
    std::print("{}", prompt);
    std::fflush(stdout); 

    std::string temp;
    std::getline(std::cin >> std::ws, temp);
    return temp;
}

void CinBuf::clearScreen()
{
    std::print("\033[2J\033[1;1H");
    std::fflush(stdout);
}

void CinBuf::getMinMaxValue(int& min, int& max){
    do{
        min = getInt("Pobierz minimalną wartość mocy: ");
        max = getInt("Pobierz maksymalną wartość mocy: ");
            if (min >= max) {
                std::print("Wartość minimalna nie może być większa/równa maksymalnej\n");
                pressEnter();
                clearScreen();
            }
        }  while(min >= max);
}