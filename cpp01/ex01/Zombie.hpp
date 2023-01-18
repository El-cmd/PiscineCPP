#ifndef ZOMBIE_HPP
    #define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
    Zombie();
    Zombie(std::string nom);
    void setName(std::string name);
    void announce();
	~Zombie();

    private:
    std::string m_name;
};

Zombie *zombieHorde(int n, std::string name);

#endif