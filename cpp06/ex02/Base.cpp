#include "Base.hpp"

Base::~Base(){}

Base *generate(void)
{
    std::srand(std::time(NULL));
    
	switch (std::rand() % 3)
	{
		case (0):
			return (reinterpret_cast<Base *>(new A));
		case (1):
			return (reinterpret_cast<Base *>(new B));
		case (2):
			return (reinterpret_cast<Base *>(new C));
		default:
			break;
	}
	return (NULL);
}

void identify(Base *p)
{
	void *ptr;
	ptr = dynamic_cast<A *>(p);
	if (ptr != NULL)
	{
		std::cout << "Object is A" << std::endl;
		return ;
	}
	ptr = dynamic_cast<B *>(p);
	if (ptr != NULL)
	{
		std::cout << "Object is B" << std::endl;
		return ;
	}
	ptr = dynamic_cast<C *>(p);
	if (ptr != NULL)
	{
		std::cout << "Object is C" << std::endl;
		return ;
	}
	std::cout << "Error Type" << std::endl;
}


void identify(Base &p)
{
	try 
	{
		A &refa = dynamic_cast<A &>(p);
		(void)refa;
		std::cout << "Object is A" << std::endl;
		return ;
	}
	catch(std::exception &badcast)
	{	
	}
	try
	{
		B &refb = dynamic_cast<B &>(p);
		(void)refb;
		std::cout << "Object is B" << std::endl;
		return ;
	}
		catch(std::exception &badcast)
	{
	}
	try
	{
		C &refc = dynamic_cast<C &>(p);
		(void)refc;
		std::cout << "Object is C" << std::endl;
		return ;
	}
	catch (std::exception &badcast)
	{
		std::cout << "Type unknown." << std::endl;
	}
}
