#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->hitPoint = 100;
    this->EnergyP = 100;
    this->AttackD = 30;
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string n) : ClapTrap(n)
{
    this->hitPoint = 100;
    this->EnergyP = 100;
    this->AttackD = 30;
    std::cout << "FragTrap surchage constructor called\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap default destructor called\n";
}

void FragTrap::attack(const std::string& target)
{
    if (this->getNrg() <= 0 || this->getHit() <= 0)
    {
        std::cout << "You don't have any Energy Point or Hit point for attack somebody\n";
        return ;
    }
    this->EnergyP -= 1;
    std::cout << "FragTrap "<< this->name << " attacks " << target << ", causing " << this->AttackD << " points of damage!\n";
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoint <= 0)
    {
        std::cout << "FragTrap " << this->name << " has no more Hitpoint, he can't take more damages\n";
        return ;
    }
    this->hitPoint -= amount; 
    std::cout <<  "FragTrap " << this->name << " take " << amount << " damage, he still has " << this->hitPoint << std::endl;
    if (this->hitPoint <= 0)
    {
        std::cout << "FragTrap " << this->name << " is KO\n";
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (this->EnergyP <= 0 || this->hitPoint <= 0)
    {
        std::cout << "FragTrap " << this->name << " has no more enough Energy point or Hit point for be repaired\n";
        return ;
    }
    this->EnergyP -= 1;
    this->hitPoint += amount;
    std::cout << "FragTrap " << this->name << " recharges and retake " << amount << " life points, he still has " << this->hitPoint << std::endl;
}
void FragTrap::highFivesGuys()
{
    std::cout << "Si tu pouvais faire un hight five à ce bg a coté de toi, Et oui jai brissé le 4e mures" << std::endl;
}