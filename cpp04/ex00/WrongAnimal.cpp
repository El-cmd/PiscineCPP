#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong")
{
    std::cout << "Default WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal &other) : type(other.getType())
{
    std::cout << "Copie constructor called\n";
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &other)
{
    this->type = other.getType();
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Default WrongAnimal destructor called\n";
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong Animal make a false sound\n";
}

