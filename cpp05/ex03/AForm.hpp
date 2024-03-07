#ifndef AForm_HPP
	#define AForm_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	public:

	/*Coplien*/
	AForm();
	AForm(std::string n);
	AForm(std::string n, int gts, int gte);
	AForm(AForm const &other);
	virtual ~AForm();
	virtual AForm &operator=(AForm const &other);

	/*Getter*/
	virtual bool getIsSigned()const;
	virtual int getGradeToSign() const;
	virtual int getGradeToExecute() const;
	virtual const std::string getName() const;


	/*exec focntion*/
	virtual int execute(Bureaucrat const &executor) const = 0;
	virtual void beSigned(Bureaucrat &v);

	protected:
	std::string _name;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, AForm &f);


#endif