#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::Zombie(std::string nom)
{
	m_name = nom;
}

void Zombie::setName(std::string name)
{
    m_name = name;
}

void Zombie::announce()
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
	std::cout << m_name << " Have been destroyed\n";
}