#include "AMateria.hpp"

AMateria::AMateria() : _type("")
{}


AMateria::AMateria(std::string const &type) : _type(type)
{
    std::cout << "AMateria constructor with type called\n";
}

AMateria::AMateria(AMateria const &other)
{
    *this = other;
}

AMateria::~AMateria()
{
    std::cout << "AMateria default destructor called\n";
}

const std::string &AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "AMateria use " << this->_type << "on " << target.getName() << std::endl;
}

AMateria *AMateria::clone() const
{
    return (AMateria*)this;
}

