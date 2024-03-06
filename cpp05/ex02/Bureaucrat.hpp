#ifndef BUREAUCRAT_HPP
    #define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    public:

    /*---------coplian------------*/
    Bureaucrat();
    Bureaucrat(std::string n, int g);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();

    /*---------getter------------*/
    int getGrade() const;
    std::string getName() const;

    /*---------exec------------*/
    void down();
    void up();
	void signForm(AForm &f);
    void executeForm(AForm const &form);
    
    private:
    std::string const _name;
    int _grade;


    /*---------exeptions------------*/
    public:
    class GradeTooHighException: public std::exception
    {
        public:
        virtual const char *what() const throw()
        {
            return ("Grade is too high\n");
        }
    };

    class GradeTooLowException: public std::exception
    {
        public:
        virtual const char *what() const throw()
        {
            return ("Grade is too low\n");
        }
    };

};

std::ostream &operator<<(std::ostream &out, Bureaucrat &b);




#endif