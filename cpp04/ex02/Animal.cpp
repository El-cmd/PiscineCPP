#include "Animal.hpp"

Animal::Animal() : type("Default")
{
    std::cout << "Default Animal constructor called\n";
}

Animal::~Animal()
{
    std::cout << "Default Animal destructor called\n";
}

std::string Animal::getType() const
{
    return this->type;
}
