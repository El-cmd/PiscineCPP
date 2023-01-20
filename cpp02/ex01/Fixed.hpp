#ifndef FIXED_HPP
    #define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    public:
    Fixed();
    Fixed(Fixed &autre);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    Fixed   &operator=( Fixed const &result );
    ~Fixed();

    private:
    int const static fractBit = 8;
    int nbFix;

};

#endif 