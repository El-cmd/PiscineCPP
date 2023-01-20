#include "Fixed.hpp"

Fixed::Fixed() : nbFix(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed &autre)
{
    std::cout << "Copy constructor called\n";
    Fixed::nbFix = autre.getRawBits();
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return this->nbFix;
}

Fixed   &Fixed::operator=( Fixed const &result )
{
    std::cout << "Copy assignement operator called\n";
    this->nbFix = result.getRawBits();
    return *this;
}

void Fixed::setRawBits(int const row)
{
    this->nbFix = row;
}