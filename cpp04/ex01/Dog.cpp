#include "Dog.hpp"

Dog::Dog() : Animal(), ptr(new Brain())
{
    this->type = "Dog";
    std::cout << "Default Dog constructor called\n";
}

Dog::~Dog()
{
    delete this->ptr;
    std::cout << "Default Dog destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "Wouaf Wouaf\n";
}