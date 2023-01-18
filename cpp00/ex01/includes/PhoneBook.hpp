#ifndef PHONEBOOK_HPP
    #define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
    public :
    PhoneBook();
    void Header();
    void add(int x);
    void search();

    private :
    Contact m_contact[8];
};

#endif