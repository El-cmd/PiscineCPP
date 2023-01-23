#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::string tab = "tobiie";
    ClapTrap test(tab);
    test.attack(tab);
    test.takeDamage(11);
    test.beRepaired(2);
    return 0;
}