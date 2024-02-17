#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
	int i = 0;
	while (i < 4)
	{
		this->_inventaire[i] = NULL;
		i++;
	}
	std::cout << "Character default constructor called\n";
}

Character::Character(Character const &other) : _name(other._name)
{
	*this = other;
	std::cout << "Character copy constructor called\n";

}

std::string const &Character::getName() const
{
	return this->_name;
}

Character::~Character()
{
	int i = 0;
	while (i < 4)
	{
		if (this->_inventaire[i])
		{
			this->unequip(i);
			delete this->_inventaire[i];
		}
		i++;
	}
	std::cout << "Character default destructor called\n";
}

Character &Character::operator=(Character const &other)
{
	if (&other != this)
	{
		this->_name = other.getName();
		int i = 0;
		while (i < 4)
		{
			if (this->_inventaire[i] != NULL)
				delete this->_inventaire[i];
			i++;
		}
		i = 0;
		while (i < 4)
		{
			if (this->_inventaire[i] != NULL)
				this->_inventaire[i] = other._inventaire[i];
			i++;
		}
	}
	return *this;

}

//----Fonction Perso----//

void Character::equip(AMateria *m)
{
	int i = 0;
	while (i < 4)
	{
		if (this->_inventaire[i] == NULL)
		{
			this->_inventaire[i] = m;
			//std::cout << "le Character " << this->getName() << " s'est équipé de " << m->getType() << " a la place " << i << std::endl;
			return ;
		}
		i++;
	}
	if (i == 4)
	{
		std::cout << "le Character " << this->getName() << " porte trop de Materias sur lui\n"; 
		return ;
	}
}

void Character::unequip(int idx)
{
	if (this->_inventaire[idx])
		this->_inventaire[idx] = NULL;
	else
	{
		std::cout << "Le Materia numéro " << idx << " n'existe pas\n";
		return ;
	}
	std::cout << "Le Materia numéro " << idx << " à été d'éséquipé\n";

}

void Character::use(int idx, ICharacter &target)
{
	if (this->_inventaire[idx])
		this->_inventaire[idx]->use(target);
}
