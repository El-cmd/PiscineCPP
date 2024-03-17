#include "easyfind.hpp"


int main(void)
{
	try 
	{
		std::vector<int> a(6, 1);
		a.push_back(7);
		a.push_back(4);
		a.push_back(9);
 		std::vector<int>::iterator it =  easyfind(a, 35);

		std::cout << *it << std::endl;
	}
    catch (const std::exception &e)
    {
        std::cerr << "Out of range\n";
		return 1;
    }
	return 0;
}