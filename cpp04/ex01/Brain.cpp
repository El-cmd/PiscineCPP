#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default Brain constructor called\n";
}

Brain::Brain(Brain &other)
{
    std::cout << "Copie constructor called\n";
    *this = other;
}

Brain &Brain::operator=(Brain &other)
{
    int i = 0;
    while (i < 100)
    {
        this->ideas[i] = other.ideas[i];
        i++;
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Default Brain destructor called\n";
}

