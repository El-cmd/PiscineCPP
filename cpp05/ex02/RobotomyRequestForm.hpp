#ifndef ROBOTOMYREQUESTFORM_HPP
	#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm: public Form
{
	public:
	RobotomyRequestForm(std::string t);
	~RobotomyRequestForm();

	private:
	std::string target;
};

#endif