#ifndef SHRUBBERYCREATIONFORM_HPP
	#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class AForm;


class ShrubberyCreationForm: public AForm
{
	public:
	/*Coplien*/
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	/*Getter*/
	std::string getTarget() const;
	

	/*exec focntion*/
	int execute(Bureaucrat const &executor) const;

	private:
	std::string _target;
};

#endif