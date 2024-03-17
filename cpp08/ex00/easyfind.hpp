#ifndef EASYFIND_HPP
	#define EASYFIND_HPP

#include <string>
#include <iostream>
#include <exception>
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
    throw std::out_of_range("La valeur cherchée n'est pas dans le tableau\n");
}

 #endif