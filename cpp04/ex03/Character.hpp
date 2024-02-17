#ifndef CHARACTER__HPP
    #define CHARACTER__HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_inventaire[4];

    public:
        Character(std::string const &name);;
        Character(Character const &other);
        std::string const &getName() const;
        void equip(AMateria *a);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
        ~Character();
        Character &operator=(Character const &other);
};

#endif