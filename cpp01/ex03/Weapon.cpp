#include "Weapon.hpp"

Weapon::Weapon(std::string arme)
{
    setType(arme);
}

Weapon::~Weapon()
{}

const std::string& Weapon::getType()
{
    return (this->type);
}

void Weapon::setType(std::string input)
{
    this->type = input;
}