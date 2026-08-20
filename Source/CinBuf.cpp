#include "CinBuf.h"



void CinBuf::pressEnter() const
{
    std::cout << "\nNacisnij Enter, aby kontynuowac...";
    std::cin.ignore(); 
    std::cin.get();    
    std::system("cls");
}


int CinBuf::getInt(const std::string& prompt)
{
    auto temp{0};
    
    std::cout << prompt; 
    
    while (!(std::cin >> temp)) {
        std::cout << "Blad: Nieprawidlowy znak. Wprowadz liczbe!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::cout << "Wcisnij Enter aby sprobowac ponownie...";
        std::cin.get();
        std::cout << "\n" << prompt; 
    }
    return temp;
}