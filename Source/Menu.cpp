#include "Menu.h"


//TODO TOMORROW
// Give some information when you choose the option. When you're printing "Starship navy", tell it.


void Menu::wyswietlMenu() const
{
    std::println("{:=^50}", " MENU GLOWNE ");
    std::print(
    R"( 
1. Dodaj statek bojowy
2. Dodaj transporter
3. Wyswietl flote
4. Sortuj po...
5. Zlicz po...
6. Usuń po...
7. Oblicz całkowitą...
8. Pobierz...
9. Eksportuj...
0. Wyjscie z programu
> )");
}

void Menu::uruchomMenu()
{
    auto wybor{0};
    Choose_Option option;

    do
    {
        wyswietlMenu();
        wybor = buff.getInt("Wybierz opcje: ");

        option = static_cast<Choose_Option>(wybor);

        auto it = actions.find(option);

        if (it != actions.end())    it->second();
        else                        std::print("Nieprawidłowy wybór!\n");
       
    } while (option != Choose_Option::Exit);
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
    std::print("Liczba statkow powyzej podanej mocy: {}\n",flota.zliczPowyzejMocy(moc));
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


void Menu::uruchomMenuSortowania(){
    auto wybor{0};
    Sort_Option option;

    do
    {
        wyswietlMenuSortowania();
        wybor = buff.getInt("Wybierz opcje: ");

        option = static_cast<Sort_Option>(wybor);

        auto it = sortActions.find(option);

        if (it != sortActions.end())    it->second();
        else                            std::print("Nieprawidłowy wybór!\n");
       
    } while (option != Sort_Option::Go_Back);
}
void Menu::wyswietlMenuSortowania() const{
std::println("{:=^50}", " MENU SORTOWANIA ");
    std::print(
    R"( 
1. ...po Zasięgu
2. ...po Nazwie
3. ...po Masie
4. ...po Mocy Napędu
0. Cofnij
> )");
}

void Menu::wyswietlMenuSortowaniaPo() const
{
    std::println("{:=^50}", " JAK CHCESZ SORTOWAĆ? ");
    std::print(
    R"( 
1. Rosnąco
2. Malejąco
0. Cofnij
> )");
}


void Menu::by_range(){
    auto wybor{0};
    Sort_Option_By option;
    do{
        wyswietlMenuSortowaniaPo();
        wybor = buff.getInt("Wybierz opcje: ");

        option = static_cast<Sort_Option_By>(wybor);

        auto it = sortActionsByRange.find(option);

        if (it != sortActionsByRange.end())    {  it->second(); break; }
        else                            std::print("Nieprawidłowy wybór!\n");
    }while(option != Sort_Option_By::Go_Back);

}
void Menu::by_name(){
    auto wybor{0};
    Sort_Option_By option;
    do{
        wyswietlMenuSortowaniaPo();
        wybor = buff.getInt("Wybierz opcje: ");

        option = static_cast<Sort_Option_By>(wybor);

        auto it = sortActionsByName.find(option);

        if (it != sortActionsByName.end())    {  it->second(); break; }
        else                            std::print("Nieprawidłowy wybór!\n");
    }while(option != Sort_Option_By::Go_Back);

}
void Menu::by_weight(){
    auto wybor{0};
    Sort_Option_By option;
    do{
        wyswietlMenuSortowaniaPo();
        wybor = buff.getInt("Wybierz opcje: ");

        option = static_cast<Sort_Option_By>(wybor);

        auto it = sortActionsByWeight.find(option);

        if (it != sortActionsByWeight.end())  {  it->second(); break; }
        else                            std::print("Nieprawidłowy wybór!\n");
    }while(option != Sort_Option_By::Go_Back);

}
void Menu::by_drive_unit(){
    auto wybor{0};
    Sort_Option_By option;
   do{
        wyswietlMenuSortowaniaPo();
        wybor = buff.getInt("Wybierz opcje: ");

        option = static_cast<Sort_Option_By>(wybor);

        auto it = sortActionsByDriveUnit.find(option);

        if (it != sortActionsByDriveUnit.end())    {  it->second(); break; }
        else                            std::print("Nieprawidłowy wybór!\n");
    }while(option != Sort_Option_By::Go_Back);

}




// template <class T>
// void uruchomMenuSortowaniaPo()
// {
//     std::unordered_map<Sort_Option_By, std::function<void()>> sortOptionsBy{
//         {Sort_Option_By::Growing, [this]{
//             buff.clearScreen(); 
//             T. 
//             buff.pressEnter(); 
//         }},
//         {Sort_Option_By::Descending, [this]{
//             buff.clearScreen(); 
//             by_range(); 
//             buff.pressEnter(); 
//         }},
//         {Sort_Option_By::Go_Back, [this]{
//             buff.clearScreen();
//         }}
//     };
// }



void Menu::wyswietlMenuZliczStatki() const{
    std::println("{:=^50}", " MENU ZLICZANIA ");
    std::print(
    R"( 
1. ...w Przedziale Mocy
2. ...w Przedziale Mase
3. ...w Przedziale Zasiegu
0. Cofnij
> )");
}
void Menu::wyswietlMenuUsun() const{
    std::println("{:=^50}", " MENU USUWANIA ");
    std::print(
    R"( 
1. ...w Przedziale Mocy
2. ...w Przedziale Mase
3. ...w Przedziale Zasiegu
0. Cofnij
> )");
}
void Menu::wyswietlMenuOblicz() const{
    std::println("{:=^50}", " MENU OBLICZANIA ");
    std::print(
    R"( 
1. ...Moc Floty
2. ...Masę Floty
3. ...Zasięg Floty
0. Cofnij
> )");
}
void Menu::wyswietlMenuPobierzStatki() const{
    std::println("{:=^50}", " MENU POBIERANIA ");
    std::print(
    R"( 
1. ...Nazwę statków (Po Literce)
2. ...Moc statków (przedział)
3. ...Zasięg statków (przedział)
4. ...Masę statków (przedział)
0. Cofnij
> )");
}
void Menu::wyswietlMenuEksortuj() const{
    std::println("{:=^50}", " MENU EKSPORTOWANIA ");
    std::print(
    R"( 
1. ...Nazwę statków
2. ...Moc statków
3. ...Zasięg statków
4. ...Masę statków
0. Cofnij
> )");
}

void Menu::uruchomMenuZliczStatki(){}
void Menu::uruchomMenuUsun(){}
void Menu::uruchomMenuPobierzStatki(){}
void Menu::uruchomMenuEksportuj(){}