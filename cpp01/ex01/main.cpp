#include "Zombie.hpp"

int main()
{
    int i = -1;
    std::cout << "Creation d'une horde de zombie\n\n";
    Zombie *paul = zombieHorde(10, "PAUL");

    while (++i < 10)
        paul[i].announce();
    delete [] paul;
    return 0;
}