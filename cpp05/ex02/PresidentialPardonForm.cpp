#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string t): Form("PresidentialPardonForm", 25, 5)
{
	this->target = t;
	std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}
