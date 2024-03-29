#ifndef SCAVTRAP_HPP
    #define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
    ScavTrap();
    ScavTrap(std::string n);
    ScavTrap   &operator=( ScavTrap &SP );
    void guardGate();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    ~ScavTrap();

    private:
};

#endif