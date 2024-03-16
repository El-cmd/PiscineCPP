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
	const std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;	
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
			return ("Error: Grade is too low to be signed\n");
		}
	};

	class GradeTooHighException: public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Error: Grade is too high to be signed\n");
		}
	};
};

std::ostream &operator<<(std::ostream &out, Form &f);


#endif