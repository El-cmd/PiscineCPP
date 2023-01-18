#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    size_t pos;
    if (ac == 4)
    {   
        std::ifstream in(av[1]);
        std::string file = av[1];
        std::string replace = ".replace";
        file += replace;
        std::ofstream out(file.c_str());
        std::string final;
        std::string test = av[2];
        std::string tmp = av[3];

        if (in)
        {
            if(std::getline(in, final, '\0'))
            {
                pos = final.find(test);
                while (pos != std::string::npos)
                {
                    final.erase(pos, test.length());
                    final.insert(pos, tmp);
                    pos = final.find(test);
                }
                out << final;
            }
        }
    }
    return 0;
}