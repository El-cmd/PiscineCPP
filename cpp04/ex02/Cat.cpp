#include "Cat.hpp"

Cat::Cat() : Animal(), ptr(new Brain())
{
    this->type = "Cat";
    std::cout << "Default Cat constructor called\n";
}

Cat::Cat(Cat &other)
{
    std::cout << "Copie constructor called\n";
    type = other.type;
    ptr = new Brain(*other.ptr);
}

Cat &Cat::operator=(Cat &other)
{
    this->type = other.getType();
    delete this->ptr;
    this->ptr = new Brain(*other.ptr);
    return *this;
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