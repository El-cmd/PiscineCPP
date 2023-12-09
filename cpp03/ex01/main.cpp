#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap ethan("ethan");

    ethan.attack("bobby");
    ethan.takeDamage(20);
    ethan.beRepaired(5);

    ScavTrap alex("alex");
    ScavTrap Robert("Robert");
    alex.attack("jhon");
    alex.takeDamage(10);
    alex.guardGate();
    Robert = alex;
    Robert.takeDamage(10);
    return 0;
}