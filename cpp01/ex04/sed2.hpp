#ifndef SED2_HPP
    #define SED2_HPP

#include <fstream>
#include <string>
#include <iostream>

class Sed
{
    public:
    Sed(char**av);

    private:
    std::string s1;
    std::string s2;
};

#endif