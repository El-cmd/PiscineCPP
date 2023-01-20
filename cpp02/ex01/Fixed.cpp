#include "Fixed.hpp"

Fixed::Fixed() : nbFix(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const a) : nbFix(a << fractBit)
{
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(float const a) : nbFix((int)roundf(a * (1 << fractBit)))
{
    std::cout << "Float constructor called\n";
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed const &autre)
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

std::ostream &operator<<(std::ostream &out, Fixed const &result)
{
    out << result.toFloat();
    return (out);
}

void Fixed::setRawBits(int const row)
{
    this->nbFix = row;
}

float Fixed::toFloat() const
{
    return static_cast<float>(this->getRawBits()) / (1 << fractBit);
}

int Fixed::toInt() const
{
    return static_cast<int>(this->getRawBits()) / (1 << fractBit);
}