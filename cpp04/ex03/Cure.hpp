#ifndef CURE__HPP
    #define CURE__HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure(); 
        Cure(Cure const &other);
        ~Cure();
        Cure &operator=(Cure const &other);
        virtual void use(ICharacter &target);
        virtual AMateria *clone() const;
};

#endif