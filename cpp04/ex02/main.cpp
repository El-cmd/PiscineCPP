#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    //Animal a; On ne peut pas l'instancier car elle est completement abstraite
    Cat b;
    Cat c(b);
    Dog g;
    return 0;
}