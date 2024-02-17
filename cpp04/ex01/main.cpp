#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define NB_ANIMALS 10

int main()
{
    Animal    *animal[NB_ANIMALS];

    for (int i = 0; i < NB_ANIMALS; i++)
    {
        if ((i % 2) == 0)
            animal[i] = new Dog();
        else
            animal[i] = new Cat();
        std::cout << "Animal ["<< i << "] has been created with ["<< animal[i]->getType() << "] type." << std::endl;
    }
    Cat b;
    Cat c(b);

    std::cout << "DEEP COPY!!" << std::endl;
	std::cout << "-----------------------------" << std::endl;
    for (int j = 0; j < NB_ANIMALS; j++)
    {
        delete animal[j];
        std::cout << "Animal ["<< j << "] has been destroyed." << std::endl;
    }
    return 0;
}