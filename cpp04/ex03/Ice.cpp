#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
    //std::cout << "Ice default constructor are called\n";
}

Ice::Ice(Ice const &other): AMateria("ice")
{
    *this = other;
}

Ice::~Ice()
{
    //std::cout << "Ice default destructor called\n";
}

Ice &Ice::operator=(Ice const &other)
{
    if (this != &other)
        this->_type = other._type;
    return *this;
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

AMateria *Ice::clone() const
{
    return (new Ice(*this));
}