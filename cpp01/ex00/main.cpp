#include "Zombie.hpp"

int main()
{
	std::cout << "Creation de Edgar sur la Heap \n";
	Zombie *zombi = newZombie("Edgar");
	zombi->announce();
	delete zombi;
	std::cout << "Creation de Paul sur la Stack\n";
	randomChump("Paul");
	return 0;
}
