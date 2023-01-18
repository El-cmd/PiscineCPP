#ifndef CONTACT_HPP
    #define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact 
{
    public :
    Contact();
    void newContact(int x);
    int  printOrNot();
    void printindex();
    void printFname();
    void printLname();
    void printnick();
    void printContact();

    private :
    int m_index;
    std::string m_fName;
    std::string m_lName;
    std::string m_nickname;
    std::string m_pNumber;
    std::string m_secret;
};

#endif