#ifndef WRONGANIMAL_HPP
    #define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
    public:
    WrongAnimal();
    WrongAnimal(WrongAnimal &other);
    WrongAnimal &operator=(WrongAnimal &other);
    std::string getType() const;
    ~WrongAnimal();
    void makeSound() const;
    protected:
    std::string type;
};

#endif