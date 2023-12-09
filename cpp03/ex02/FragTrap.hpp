#ifndef FRAGTRAP_HPP
    #define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
    FragTrap();
    FragTrap(std::string n);
    FragTrap   &operator=( FragTrap &FP );
    ~FragTrap();
    void highFivesGuys();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    private:

};

#endif