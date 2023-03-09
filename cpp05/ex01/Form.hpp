#ifndef FORM_HPP
	#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Form
{

	public:
	Form();
	~Form();

	private:
	std::string const name;
	bool isSigned;
	int const gradeToSign;
	int const gradeToExecute;
};


#endif