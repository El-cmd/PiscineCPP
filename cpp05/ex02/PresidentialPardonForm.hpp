#ifndef PRESIDENTIALPARDONFORM_HPP
	#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form
{
	public:
	PresidentialPardonForm(std::string t);
	~PresidentialPardonForm();

	private:
	std::string target;

};

#endif