#ifndef FIXED_HPP
    #define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    public:
    Fixed();
    Fixed(Fixed const &autre);
    Fixed(int const a);
    Fixed(float const a);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat(void) const;
    int toInt(void) const;
    static Fixed &min(Fixed &a, Fixed&b);
    static const Fixed &min(Fixed const &a, Fixed const &b);
    static const Fixed &max(Fixed const &a, Fixed const &b);
    static Fixed &max(Fixed &a, Fixed &b);
    Fixed   &operator=( Fixed const &result );
    Fixed operator+(Fixed const &a) const;
    Fixed operator-(Fixed const &a) const;
    Fixed operator*(Fixed const &a) const;
    Fixed operator/(Fixed const &a) const;
    Fixed operator++();
    Fixed operator--();
    Fixed operator++(int);
    Fixed operator--(int);
    bool operator>=(Fixed const &a);
    bool operator<=(Fixed const &a);
    bool operator!=(Fixed const &a);
    bool operator==(Fixed const &a);
    bool operator<(Fixed const &a);
    bool operator>(Fixed const &a);

    ~Fixed();

    private:
    int const static fractBit = 8;
    int nbFix;

};

std::ostream &operator<<(std::ostream &out, Fixed const &result);

#endif   