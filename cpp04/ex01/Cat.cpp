#include "Cat.hpp"

Cat::Cat() : Animal(), ptr(new Brain())
{
    this->type = "Cat";
    std::cout << "Default Cat constructor called\n";
}

Cat::~Cat()
{
    delete this->ptr;
    std::cout << "Default Cat destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << "Miaou Miaou\n";
}