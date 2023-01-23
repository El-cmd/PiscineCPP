#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong")
{
    std::cout << "Default WrongAnimal constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Default WrongAnimal destructor called\n";
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong Animal make a false sound\n";
}