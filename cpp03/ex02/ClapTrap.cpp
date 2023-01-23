#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Default constructor called\n";
}

ClapTrap::ClapTrap(std::string n): name(n), hitPoint(10), EnergyP(10), AttackD(0)
{
    std::cout << "ClapTrap Surcharge constructor called\n";
}

ClapTrap::ClapTrap(ClapTrap &copie) : name(copie.getname()), hitPoint(copie.getHit()), EnergyP(copie.getNrg()), AttackD(copie.getAttak())
{
    std::cout << "ClapTrap Copie constructor called\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Default destructor called\n";
}
int ClapTrap::getHit()
{
    return this->hitPoint;
}

int ClapTrap::getAttak()
{
    return this->AttackD;
}

int ClapTrap::getNrg()
{
    return this->EnergyP;
}

std::string ClapTrap::getname()
{
    return this->name;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->EnergyP <= 0 || this->hitPoint <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has no more enough Energy point or Hit point for be repaired\n";
        return ;
    }
    this->EnergyP -= 1;
    this->hitPoint += amount;
    std::cout << "ClapTrap " << this->name << " recharges and retake " << amount << " life points, he still has " << this->hitPoint << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoint <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has no more Hitpoint, he can't take more damages\n";
        return ;
    }
    this->hitPoint -= amount; 
    std::cout <<  "ClapTrap " << this->name << " take " << amount << " damage, he still has " << this->hitPoint << std::endl;
    if (this->hitPoint <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is KO\n";
    }
}

void ClapTrap::attack(const std::string& target)
{
    if (this->getNrg() <= 0 || this->getHit() <= 0)
    {
        std::cout << "You don't have any Energy Point or Hit point for attack somebody\n";
        return ;
    }
    this->EnergyP -= 1;
    std::cout << "ClapTrap "<< this->name << " attacks " << target << ", causing " << this->AttackD << " points of damage!\n";
}