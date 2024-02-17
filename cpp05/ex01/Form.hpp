#ifndef FORM_HPP
	#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
	Form();
	Form(std::string n, int gts, int gte);
	Form(Form const &other);
	Form &operator=(Form const &other);
	~Form();
	std::string getName();
	bool getIsSigned();
	int getGradeToSign();
	int getGradeToExecute();	
	void beSigned(Bureaucrat &v);

	private:
	std::string const _name;
	bool isSigned;
	int const gradeToSign;
	int const gradeToExecute;

	public:
	class GradeTooLowException: public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Grade is too low to be signed\n");
		}
	};

	class GradeTooHighException: public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Grade is too high to be signed\n");
		}
	};
};

std::ostream &operator<<(std::ostream &out, Form &f);


#endif