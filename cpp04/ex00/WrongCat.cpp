#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "Default WrongCat constructor called\n";
}

WrongCat::~WrongCat()
{
    std::cout << "Default WrongCat destructor called\n";
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong Cat make a false sound\n";
}