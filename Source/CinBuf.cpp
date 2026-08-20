#include "CinBuf.h"



void CinBuf::pressEnter() const
{
    std::cout << "\nNacisnij Enter, aby kontynuowac...";
    std::cin.ignore(); 
    std::cin.get();    
    std::cout << "\033[2J\033[1;1H";
}


int CinBuf::getInt(std::string_view prompt) {
    int temp{0};

    while (true) {
        std::print("{}", prompt);
        std::fflush(stdout); 

        if (std::cin >> temp) {
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
}