#include "Animal.hpp"

Animal::Animal() : type("Default")
{
    std::cout << "Default Animal constructor called\n";
}

Animal::Animal(Animal &other)
{
    *this = other;
}

Animal &Animal::operator=(Animal &other)
{
    this->type = other.getType();
    return *this;
}

Animal::~Animal()
{
    std::cout << "Default Animal destructor called\n";
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Prout\n";
}