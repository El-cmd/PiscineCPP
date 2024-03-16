#ifndef EASYFIND_HPP
	#define EASYFIND_HPP

#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>

template<typename T>
typename T::iterator easyfind(T& container, int n)
{
    typename T::iterator it = container.begin();
    while (it != container.end()) {
        if (*it == n) {
            return it; // Retourne un itérateur vers l'élément trouvé
        }
        ++it;
    }
    return container.end(); // Retourne un itérateur de fin si l'élément n'est pas trouvé
}

 #endif