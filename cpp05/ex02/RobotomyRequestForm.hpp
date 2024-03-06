#ifndef ROBOTOMYREQUESTFORM_HPP
	#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class AForm;

class RobotomyRequestForm: public AForm
{
	public:
	/*Coplien*/
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm &other);
	~RobotomyRequestForm();

	/*Getter*/
	std::string getTarget() const;
	

	/*exec focntion*/
	void execute(Bureaucrat const &executor) const;

	private:
	std::string _target;
};

#endif