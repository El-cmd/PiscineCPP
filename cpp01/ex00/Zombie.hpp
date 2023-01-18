#ifndef ZOMBIE_HPP
    #define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
    Zombie(std::string nom);
    void announce();
	~Zombie();

    private:
    std::string m_name;
};

void	randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif