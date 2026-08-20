#ifndef CIN_BUF_H
#define CIN_BUF_H

#include <iostream>
#include <limits>
#include <string>

class CinBuf
{
public:
    CinBuf() = default;
    ~CinBuf() = default;

    void pressEnter() const;
    void clearScreen();
    int getInt(const std::string&);
    std::string getString(const std::string&);

};





#endif //CIN_BUF_H