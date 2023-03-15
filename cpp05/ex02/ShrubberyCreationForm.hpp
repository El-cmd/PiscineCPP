#ifndef SHRUBBERYCREATIONFORM_HPP
	#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
	public:
	ShrubberyCreationForm(std::string t);
	~ShrubberyCreationForm();

	private:
	std::string target;
	
};

#endif