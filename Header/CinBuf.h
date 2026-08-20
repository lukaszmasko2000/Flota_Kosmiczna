#ifndef CIN_BUF_H
#define CIN_BUF_H

#include <iostream>
#include <limits>

class CinBuf
{
public:
    CinBuf() = default;
    ~CinBuf() = default;

    void pressEnter() const;
    int getInt(const std::string&);

};





#endif //CIN_BUF_H