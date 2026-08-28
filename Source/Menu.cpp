#include "Menu.h"



//Show the Interface of the Menu (Frontend)
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


//Do the background stuff in the menu
void Menu::uruchomMenu()
{
    auto wybor{0};          /*Init int variable*/
    Choose_Option option;   /*Init enum object*/

    flota.dodajStatek(std::make_unique<StatekBojowy>("X-Wing", 15, 500, 5));      
    flota.dodajStatek(std::make_unique<Transporter>("Cargomaster", 120, 800, 80)); 
    flota.dodajStatek(std::make_unique<StatekBojowy>("Niszczyciel", 450, 2500, 50)); 
    flota.dodajStatek(std::make_unique<Transporter>("Shuttle-T4", 45, 400, 20)); 

    do
    {
        wyswietlMenu();                             /*Show The Menu*/
        wybor = buff.getInt("Wybierz opcje: ");     /*Get the value from User*/

        option = static_cast<Choose_Option>(wybor); /*Convert it into Enum Class*/

        auto it = actions.find(option);             /*Giving users option into iterator*/

        if (it != actions.end())    it->second();                           /*If it's exist, it choose the option*/
        else                        std::print("Nieprawidłowy wybór!\n");   /*If not, then the right responde for user*/
       
    } while (option != Choose_Option::Exit);       /*Do While is ended if user choose Exit Value (0)*/
}


//Add Ship Fighter
void Menu::addStatekBojowy()
{
    auto nazwa      { buff.getString("Podaj nazwe statku bojowego: ") };
    auto masa       { buff.getInt("Podaj mase statku (w tonach): ") };
    auto mocNapedu  { buff.getInt("Podaj moc napedu statku (w MW): ") };
    auto silaOgnia  {buff.getInt("Podaj sile ognia statku: ")};

    flota.dodajStatek(std::make_unique<StatekBojowy>(nazwa, masa, mocNapedu, silaOgnia));
}

//Add Transporter
void Menu::addTransporter()
{
    auto nazwa      {buff.getString("Podaj nazwe transportera: ")};
    auto masa       {buff.getInt("Podaj mase transportera (w tonach): ")};
    auto mocNapedu  {buff.getInt("Podaj moc napedu transportera (w MW): ")};
    auto przestrzen {buff.getInt("Podaj przestrzen transportera (w m^3): ")};

    flota.dodajStatek(std::make_unique<Transporter>(nazwa, masa, mocNapedu, przestrzen));
}

/*------------------------------------TO REMOVE-------------------------------------------*/
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
/*---------------------------------------------------------------------------------------*/

//Sorting Menu Interface
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

//Do the background stuff in the sorting menu
void Menu::uruchomMenuSortowania(){
    auto        wybor{0};
    Sort_Option option;

    do
    {
        wyswietlMenuSortowania();
        wybor =     buff.getInt("Wybierz opcje: ");
        option =    static_cast<Sort_Option>(wybor);
        auto it =   sortActions.find(option);
        if (it != sortActions.end())    it->second();
        else                            std::print("Nieprawidłowy wybór!\n");
       
    } while (option != Sort_Option::Go_Back);
}

//Sub-Sorting Menu Interface
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

//Do the background stuff in the sub-sorting menu
void Menu::by_range(){
    auto wybor{0};
    Sort_Option_By option;
    do {
        wyswietlMenuSortowaniaPo();
        wybor =     buff.getInt("Wybierz opcje: ");
        option =    static_cast<Sort_Option_By>(wybor);
        auto it =   sortActionsByRange.find(option);

        if (it != sortActionsByRange.end())     {it->second(); break;} 
        else                                    std::print("Nieprawidłowy wybór!\n");
    }   while(option != Sort_Option_By::Go_Back);
}
void Menu::by_name(){
    auto wybor{0};
    Sort_Option_By option;
    do {
        wyswietlMenuSortowaniaPo();
        wybor =     buff.getInt("Wybierz opcje: ");
        option =    static_cast<Sort_Option_By>(wybor);
        auto it =   sortActionsByName.find(option);

        if (it != sortActionsByName.end())    {it->second(); break;}
        else                                   std::print("Nieprawidłowy wybór!\n");
    }   while(option != Sort_Option_By::Go_Back);
}

void Menu::by_weight(){
    auto wybor{0};
    Sort_Option_By option;
    do {
        wyswietlMenuSortowaniaPo();
        wybor =     buff.getInt("Wybierz opcje: ");
        option =    static_cast<Sort_Option_By>(wybor);
        auto it =   sortActionsByWeight.find(option);

        if (it != sortActionsByWeight.end())   {it->second(); break;}
        else                                    std::print("Nieprawidłowy wybór!\n");
    }   while(option != Sort_Option_By::Go_Back);
}

void Menu::by_drive_unit(){
    auto wybor{0};
    Sort_Option_By option;
   do {
        wyswietlMenuSortowaniaPo();
        wybor =     buff.getInt("Wybierz opcje: ");
        option =    static_cast<Sort_Option_By>(wybor);
        auto it =   sortActionsByDriveUnit.find(option);

        if (it != sortActionsByDriveUnit.end())  {it->second(); break;}
        else                                     std::print("Nieprawidłowy wybór!\n");
    }   while(option != Sort_Option_By::Go_Back);
}


void Menu::wyswietlMenuZliczStatki() const{
    std::println("{:=^50}", " MENU ZLICZANIA ");
    std::print(
    R"( 
1. ...w Przedziale Mocy
2. ...w Przedziale Masy
3. ...w Przedziale Zasiegu
0. Cofnij
> )");
}

void Menu::uruchomMenuZliczStatki(){
    auto wybor{0};
    Count_If_Option option;
   do {
        wyswietlMenuZliczStatki();
        wybor =     buff.getInt("Wybierz opcje: ");
        option =    static_cast<Count_If_Option>(wybor);
        auto it =   countIfActions.find(option);

        if (it != countIfActions.end())          {it->second(); break;}
        else                                     std::print("Nieprawidłowy wybór!\n");
    }   while(option != Count_If_Option::Go_Back);
}

void Menu::wyswietlMenuUsun() const{
    std::println("{:=^50}", " MENU USUWANIA ");
    std::print(
    R"( 
1. ...w Przedziale Mocy
2. ...w Przedziale Masy
3. ...w Przedziale Zasiegu
4. ...po Nazwie Statku
0. Cofnij
> )");
}

void Menu::uruchomMenuUsun(){
    auto wybor{0};
    Remove_If_Option option;
   do {
        wyswietlMenuUsun();
        wybor =     buff.getInt("Wybierz opcje: ");
        option =    static_cast<Remove_If_Option>(wybor);
        auto it =   removeIfActions.find(option);

        if (it != removeIfActions.end())          {it->second(); break;}
        else                                     std::print("Nieprawidłowy wybór!\n");
    }   while(option != Remove_If_Option::Go_Back);
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

void Menu::uruchomMenuOblicz(){
    auto wybor{0};
    Fold_Left_Option option;
   do {
        wyswietlMenuOblicz();
        wybor =     buff.getInt("Wybierz opcje: ");
        option =    static_cast<Fold_Left_Option>(wybor);
        auto it =   foldLeftActions.find(option);

        if (it != foldLeftActions.end())          {it->second(); break;}
        else                                     std::print("Nieprawidłowy wybór!\n");
    }   while(option != Fold_Left_Option::Go_Back);
}

void Menu::wyswietlMenuPobierzStatki() const{
    std::println("{:=^50}", " MENU POBIERANIA ");
    std::print(
    R"( 
1. ...Moc statków (przedział)
2. ...Masę statków (przedział)
3. ...Zasięg statków (przedział)
4. ...Nazwę statków (Po Literce)
0. Cofnij
> )");
}

void Menu::uruchomMenuPobierzStatki(){
    auto wybor{0};
    Filter_Option option;
   do {
        wyswietlMenuPobierzStatki();
        wybor =     buff.getInt("Wybierz opcje: ");
        option =    static_cast<Filter_Option>(wybor);
        auto it =   filterActions.find(option);

        if (it != filterActions.end())          {it->second(); break;}
        else                                     std::print("Nieprawidłowy wybór!\n");
    }   while(option != Filter_Option::Go_Back);
}

void Menu::wyswietlMenuEksortuj() const{
    std::println("{:=^50}", " MENU EKSPORTOWANIA ");
    std::print(
    R"( 
1. ...Moc statków
2. ...Masę statków
3. ...Zasięg statków
4. ...Nazwę statków
0. Cofnij
> )");
}

void Menu::uruchomMenuEksportuj(){
    auto wybor{0};
    Transform_Option option;
   do {
        wyswietlMenuEksortuj();
        wybor =     buff.getInt("Wybierz opcje: ");
        option =    static_cast<Transform_Option>(wybor);
        auto it =   transformActions.find(option);

        if (it != transformActions.end())          {it->second(); break;}
        else                                        std::print("Nieprawidłowy wybór!\n");
    }   while(option != Transform_Option::Go_Back);
}