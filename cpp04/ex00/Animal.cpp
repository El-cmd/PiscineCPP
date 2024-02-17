#include "Animal.hpp"

Animal::Animal() : type("Default")
{
    std::cout << "Default Animal constructor called\n";
}

Animal::Animal(Animal &other) : type(other.getType())
{
    std::cout << "Copie Animal constructor called\n";
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

Animal &Animal::operator=(Animal &other)
{
    this->type = other.getType();
    return *this;
}