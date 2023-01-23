#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Default Cat constructor called\n";
}

Cat::~Cat()
{
    std::cout << "Default Cat destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << "Miaou Miaou\n";
}