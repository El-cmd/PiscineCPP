#ifndef BUREAUCRAT_HPP
    #define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
    public:
    Bureaucrat();
    Bureaucrat(std::string n, int g);
    ~Bureaucrat();
    const char *GradeTooHighException();
    const char *GradeTooLowException();
    void down();
    void up();
    int getGrade();
    std::string getName();
    
    private:
    std::string const name;
    int grade;

};

#endif