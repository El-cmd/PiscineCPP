    #ifndef SED2_HPP
    #define SED2_HPP

#include <fstream>
#include <string>
#include <iostream>

class Sed
{
    public:
    Sed(char**av);
    int makeFile();
    int doSed();
    ~Sed();

    private:
    std::string s1;
    std::string s2;
    std::string file;
    std::string fileR;
};

#endif