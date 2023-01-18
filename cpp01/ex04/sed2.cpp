#include "sed2.hpp"

Sed::Sed(char **av)
{
    s1 = av[2];
    s2 = av[3];
    file = av[1];
}

Sed::~Sed()
{}


int Sed::makeFile()
{
    std::string tmp = ".replace";
    fileR = file + tmp;
    if (s1 == s2)
    {
        std::cout << "Error: Invalid parameters.\n";
        return (0);
    }
    return (1);
}

int Sed::doSed()
{
    if(Sed::makeFile() == 0)
        return (0);
    std::ifstream in(file.c_str());
    std::string final;
    size_t pos;

    if (in)
    {
        if(std::getline(in, final, '\0'))
        {
            if (final.empty())
            {
                std::cout << "Error: " << file << " is empty" << std::endl;
                return (0);
            }
            pos = final.find(s1);
            while (pos != std::string::npos)
            {
                final.erase(pos, s1.length());
                final.insert(pos, s2);
                pos = final.find(s1);
            }
            std::ofstream out(fileR.c_str());
            out << final;
        }
    }
    else
    {
        std::cout << file << " not found" << std::endl;
        return (0);
    }
    return (1);
}