#ifndef SHRUBBERYCREATIONFORM_HPP
	#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
	ShrubberyCreationForm(std::string t);
	~ShrubberyCreationForm();

	private:
	std::string target;
	
};

#endif