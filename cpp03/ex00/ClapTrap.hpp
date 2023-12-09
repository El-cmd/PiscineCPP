#ifndef CLAPTRAP_HPP
    #define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string n);
        ClapTrap(ClapTrap &copie);
        ClapTrap   &operator=( ClapTrap &CP );
        int getHit();
        int getNrg();
        int getAttak();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getname();
        ~ClapTrap();
    private:
        std::string name;
        int hitPoint;
        int EnergyP;
        int AttackD;
};

#endif