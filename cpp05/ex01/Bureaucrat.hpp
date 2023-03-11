#ifndef BUREAUCRAT_HPP
    #define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
    Bureaucrat();
    Bureaucrat(std::string n, int g);
    ~Bureaucrat();
    void down();
    void up();
    int getGrade();
    std::string getName();
	void signForm(Form &f);
    
    private:
    std::string const name;
    int grade;

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