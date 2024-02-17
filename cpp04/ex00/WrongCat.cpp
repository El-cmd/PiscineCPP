#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "Default WrongCat constructor called\n";
}

WrongCat::WrongCat(WrongCat &other)
{
    this->type = other.getType();
    std::cout << "Copie WrongCat construtor called\n";
}

WrongCat &WrongCat::operator=(WrongCat &other)
{
    this->type = other.getType();
    return *this;
}

std::string WrongCat::getType()
{
    return this->type;
}

WrongCat::~WrongCat()
{
    std::cout << "Default WrongCat destructor called\n";
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong Cat make a false sound\n";
}