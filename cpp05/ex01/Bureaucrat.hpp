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
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();
    void down();
    void up();
    int getGrade() const;
    const std::string getName() const;
	void signForm(Form &f);
    
    private:
    std::string const _name;
    int _grade;

    public:
    class GradeTooHighException: public std::exception
    {
        public:
        virtual const char *what() const throw()
        {
            return ("Error: Grade is too high\n");
        }
    };

    class GradeTooLowException: public std::exception
    {
        public:
        virtual const char *what() const throw()
        {
            return ("Error: Grade is too low\n");
        }
    };

};

std::ostream &operator<<(std::ostream &out, Bureaucrat &b);




#endif