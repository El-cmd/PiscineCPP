#include "HumanA.hpp"

HumanA::~HumanA()
{}

HumanA::HumanA(std::string input, Weapon &Arme) : name(input), m_arme(Arme)
{}

void HumanA::attack()
{
    std::cout << name << " attacks wirh their " << this->m_arme.getType() << std::endl;
    return ;
}