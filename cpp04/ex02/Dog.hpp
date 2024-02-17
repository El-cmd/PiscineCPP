#ifndef DOG_HPP
    #define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
    Dog();
    Dog(Dog &other);
    Dog &operator=(Dog &other);
    ~Dog();
    void makeSound() const;
    private:
    Brain *ptr;
};

#endif