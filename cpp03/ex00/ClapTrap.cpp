#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(std::string n): name(n), hitPoint(10), EnergyP(10), AttackD(0)
{}

ClapTrap::ClapTrap(ClapTrap &copie) : name(copie.getname()), hitPoint(copie.getHit()), EnergyP(copie.getNrg()), AttackD(copie.getAttak())
{
    std::cout << "Copie constructor called\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "Default destructor called\n";
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

//void beRepaired(unsigned int amount)
//{}
//
void takeDamage(unsigned int amount)
{
    
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap "<< this->name << " attacks " << target << ", causing " << this->AttackD << " points of damage!\n";
}