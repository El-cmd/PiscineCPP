#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Default Dog constructor called\n";
}

Dog::Dog(Dog &other)
{
    this->type = other.getType();
    std::cout << "Copie constructor called\n";
}

Dog &Dog::operator=(Dog &other)
{
    this->type = other.getType();
    return *this;
}

Dog::~Dog()
{
    std::cout << "Default Dog destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "Wouaf Wouaf\n";
}