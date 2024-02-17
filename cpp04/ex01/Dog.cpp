#include "Dog.hpp"

Dog::Dog() : Animal(), ptr(new Brain())
{
    this->type = "Dog";
    std::cout << "Default Dog constructor called\n";
}

Dog::Dog(Dog &other)
{
    std::cout << "Copie constructor called\n";
    type = other.type;
    ptr = new Brain(*other.ptr);
}

Dog &Dog::operator=(Dog &other)
{
    this->type = other.getType();
    delete this->ptr;
    this->ptr = new Brain(*other.ptr);
    return *this;
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