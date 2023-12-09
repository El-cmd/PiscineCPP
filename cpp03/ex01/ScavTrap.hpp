#ifndef SCAVTRAP_HPP
    #define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
    public:
    ScavTrap();
    ScavTrap(std::string n);
    void guardGate();
    ScavTrap   &operator=( ScavTrap &SP );
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    ~ScavTrap();

    private:
};

#endif