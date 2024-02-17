#ifndef ANIMAL_HPP
    #define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    public:
    Animal();
    Animal(Animal &other);
    Animal &operator=(Animal &other);
    virtual ~Animal();
    std::string getType() const;
    virtual void makeSound() const = 0; // <-- ici
    protected:
    std::string type;
};

#endif