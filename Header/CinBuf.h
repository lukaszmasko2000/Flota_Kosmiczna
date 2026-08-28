#ifndef CIN_BUF_H
#define CIN_BUF_H

#include <iostream>
#include <limits>
#include <string>
#include <print>
#include <string_view>

class CinBuf
{
public:
    CinBuf() = default;
    ~CinBuf() = default;

    void pressEnter() const;
    void clearScreen();
    void getMinMaxValue(int&, int&,const std::string&);
    int getInt(std::string_view);
    std::string getString(std::string_view);
    char getChar(std::string_view);

};





#endif //CIN_BUF_H