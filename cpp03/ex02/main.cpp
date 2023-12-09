#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap ethan("ethan");

    ethan.attack("bobby");
    ethan.takeDamage(2);
    ethan.beRepaired(5);

    ScavTrap alex("alex");

    alex.attack("jhon");
    alex.takeDamage(10);
    alex.guardGate();

    FragTrap manu("manu");
    FragTrap jb("jb");
    manu.takeDamage(10);
    manu.attack("patrick");
    manu.highFivesGuys();
    jb = manu;
    jb.takeDamage(20);
    return 0;
}