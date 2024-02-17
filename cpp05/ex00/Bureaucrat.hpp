#ifndef BUREAUCRAT_HPP
    #define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
    public:
    Bureaucrat();
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat(std::string n, int g);
    Bureaucrat &operator=(Bureaucrat & other);
    ~Bureaucrat();
    void down();
    void up();
    int getGrade();
    const std::string getName() const;
    
    private:
    std::string const _name;
    int _grade;

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