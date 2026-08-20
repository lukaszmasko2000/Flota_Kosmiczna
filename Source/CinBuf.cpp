#include "CinBuf.h"



void CinBuf::pressEnter() const
{
    std::cout << "\nNacisnij Enter, aby kontynuowac...";
    std::cin.ignore(); 
    std::cin.get();    
    std::system("cls");
}
