#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    int i = 0;
	while (i < 4)
	{
		this->_source[i] = NULL;
		i++;
	}
    std::cout << "MateriaSource default constructor called\n";
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
    *this = other;
    std::cout << "MateriaSource copy constructor called\n";
}

MateriaSource::~MateriaSource()
{   
    int i = 0;
    while (i < 4)
    {
        if (_source[i])
            delete _source[i];
        i++;
    }
    std::cout << "MateriaSource default destructor called\n";
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
    int i = 0;
    while (i < 4)
    {
        this->_source[i] = other._source[i];
        i++;
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    int i = 0;
    while (i < 4)
    {
        if (_source[i] == NULL)
        {
            _source[i] = m;
            return ;
        }
        i++;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;
    while (i < 4)
    {   
        if (_source[i] && _source[i]->getType() == type)
            return _source[i]->clone();
        i++;
    }
    return NULL;
}