#include "ClapTrap.hpp"

int main()
{
    ClapTrap mario("mario");
    ClapTrap bowser("bowser");
    mario.attack("bowser");
    bowser.takeDamage(9);
    bowser.attack("mario");
    mario.takeDamage(9);
    mario.beRepaired(2);
    return 0;
}