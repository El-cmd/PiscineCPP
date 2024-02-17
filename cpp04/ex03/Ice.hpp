#ifndef ICE__HPP
    #define ICE__HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(Ice const &other);
        ~Ice();
        Ice &operator=(Ice const &other);
        virtual void use(ICharacter &target);
        virtual AMateria *clone() const;
};

#endif