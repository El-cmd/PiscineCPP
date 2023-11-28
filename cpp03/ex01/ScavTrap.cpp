#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n)
{
    std::cout << "ScavTrap Surcharge constructor called\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap default destructor called\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap "<< this->name << " Enter in GUARD MODE !" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->getNrg() <= 0 || this->getHit() <= 0)
    {
        std::cout << "You don't have any Energy Point or Hit point for attack somebody\n";
        return ;
    }
    this->EnergyP -= 1;
    std::cout << "ScavTrap "<< this->name << " attacks " << target << ", causing " << this->AttackD << " points of damage!\n";
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoint <= 0)
    {
        std::cout << "Scavtrap " << this->name << " has no more Hitpoint, he can't take more damages\n";
        return ;
    }
    this->hitPoint -= amount; 
    std::cout <<  "ScavTrap " << this->name << " take " << amount << " damage, he still has " << this->hitPoint << std::endl;
    if (this->hitPoint <= 0)
    {
        std::cout << "ScavTrap " << this->name << " is KO\n";
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (this->EnergyP <= 0 || this->hitPoint <= 0)
    {
        std::cout << "ScavTrap " << this->name << " has no more enough Energy point or Hit point for be repaired\n";
        return ;
    }
    this->EnergyP -= 1;
    this->hitPoint += amount;
    std::cout << "ScavTrap " << this->name << " recharges and retake " << amount << " life points, he still has " << this->hitPoint << std::endl;
}