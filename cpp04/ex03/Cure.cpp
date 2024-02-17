#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
    //std::cout << "Cure default constructor called\n";
}

Cure::Cure(Cure const &other): AMateria("cure")
{
    *this = other;
    //std::cout << "Cure copy destructor called\n";
}

Cure::~Cure()
{
    //std::cout << "Cure default destructor called\n";
}

Cure &Cure::operator=(Cure const &other)
{
    if (this != &other)
        this->_type = other._type;
    return *this;
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}   