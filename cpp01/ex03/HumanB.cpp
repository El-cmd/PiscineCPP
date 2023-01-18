#include "HumanB.hpp"

HumanB::~HumanB()
{}

HumanB::HumanB(std::string input)
{
    name = input;
    this->m_arme = NULL;
}

void HumanB::setWeapon(Weapon &input)
{
   this-> m_arme = &input;
}

void HumanB::attack()
{
    const std::string &input = m_arme->getType();
    if (this->m_arme == NULL)
        std::cout << name << " N'a pas d'arme, il ne peut donc pas attaquer" << std::endl;
    else
        std::cout << name << " attacks with their " << input << std::endl;

}