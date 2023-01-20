#include "Fixed.hpp"

Fixed::Fixed() : nbFix(0)
{
}

Fixed::Fixed(int const a) : nbFix(a << fractBit)
{

}

Fixed::Fixed(float const a) : nbFix((int)roundf(a * (1 << fractBit)))
{

}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed const &autre)
{
    Fixed::nbFix = autre.getRawBits();
}

int Fixed::getRawBits() const
{
    return this->nbFix;
}

Fixed   &Fixed::operator=( Fixed const &result )
{
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

bool Fixed::operator>(Fixed const &a)
{
    if (this->nbFix > a.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<(Fixed const &a)
{
    if (this->nbFix < a.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>=(Fixed const &a)
{
    if (this->nbFix >= a.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<=(Fixed const &a)
{
    if (this->nbFix <= a.getRawBits())
        return true;
    return false;
}

bool Fixed::operator==(Fixed const &a)
{
    if (this->nbFix == a.getRawBits())
        return true;
    return false;
}

bool Fixed::operator!=(Fixed const &a)
{
    if (this->nbFix != a.getRawBits())
        return true;
    return false;
}

Fixed Fixed::operator+(Fixed const &a) const
{
    Fixed result;
    result.setRawBits(this->nbFix + a.nbFix);
    return result;
}

Fixed Fixed::operator-(Fixed const &a) const
{
    Fixed resultat(this->nbFix - a.nbFix);
    return resultat;
}

Fixed Fixed::operator*(Fixed const &a) const
{
    Fixed resultat(this->toFloat() * a.toFloat());
    return resultat;
}

Fixed Fixed::operator/(Fixed const &a) const
{
    Fixed resultat(this->nbFix / a.toFloat());
    return  resultat;
}

Fixed Fixed::operator++()
{
    ++this->nbFix;
    return  *this;
}

Fixed  Fixed::operator++(int)
{
    Fixed result(*this);
    this->nbFix++;
    return result;
}

Fixed Fixed::operator--()
{
    --this->nbFix;
    return  *this;
}

Fixed  Fixed::operator--(int)
{
    Fixed result(*this);
    this->nbFix--;
    return result;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return b;
    return a;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a.getRawBits() > b.getRawBits())
        return b;
    return a;
}