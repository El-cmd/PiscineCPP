#include "Form.hpp"

Form::Form(): name("Doc"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
	std::cout << "Default Form constructor called\n";
}

Form::~Form()
{
	std::cout << "Default Form destructor called\n";
}