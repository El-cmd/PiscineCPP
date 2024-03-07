#ifndef INTERN_HPP
    #define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class Intern
{
    public:

    /*_-_-Coplian_-_-_-*/
    Intern();
    Intern(Intern &other);
    ~Intern();
    Intern &operator=(Intern &other);

    /*-_-_-Member function_-_-_-_*/
    AForm *makeForm(std::string const &one, std::string two);

    public:
    class ErrInput: public std::exception
    {
        public:
        virtual const char *what() const throw()
        {
            return ("Not a valid input, retry\n");
        }
    };

};

#endif