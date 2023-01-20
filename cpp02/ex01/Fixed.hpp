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
    Fixed   &operator=( Fixed const &result );
    ~Fixed();

    private:
    int const static fractBit = 8;
    int nbFix;

};
std::ostream &operator<<(std::ostream &out, Fixed const &result);

#endif   