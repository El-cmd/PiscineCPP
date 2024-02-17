#ifndef MATERIASOURCE__HPP
    #define MATERIASOURCE__HPP

#include <string>
#include <iostream>
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
	private: 
		AMateria *_source[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const &other);
		~MateriaSource();
		MateriaSource &operator=(MateriaSource const &other);
		
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};



#endif