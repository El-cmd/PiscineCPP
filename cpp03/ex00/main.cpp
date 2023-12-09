#include "ClapTrap.hpp"

int main()
{
    ClapTrap mario("mario");
    ClapTrap bowser("bowser");
    mario.attack("bowser");
    mario.takeDamage(9);
    mario.beRepaired(2);
    bowser = mario;
    bowser.beRepaired(1);

    return 0;
}