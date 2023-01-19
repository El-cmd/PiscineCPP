#ifndef HARL_HPP
    #define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
    public:
    Harl();
    ~Harl();
    void complain(std::string level);


    private:
    void debug();
    void info();
    void warning();
    void error();
};

typedef void (Harl::*fonctPtr)(void);

#endif