#ifndef PRESIDENTIALPARDONFORM_HPP
	#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm: public AForm
{
	public:
	/*Coplien*/
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(PresidentialPardonForm &other);
	~PresidentialPardonForm();

	/*Getter*/
	std::string getTarget() const;
	

	/*exec focntion*/
	void execute(Bureaucrat const &executor) const;

	private:
	std::string _target;
};

#endif