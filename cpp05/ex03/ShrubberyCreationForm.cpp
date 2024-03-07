#include "ShrubberyCreationForm.hpp"

/*---------------coplian form-----------------*/

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 72, 45), _target("Default")
{
	std::cout << "ShrubberyCreationForm created with default target" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other): AForm(other)
{
	*this = other;
	std::cout << "ShrubberyCreationForm copied" << std::endl;	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	this->_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

/*----------------------Getter-------------------*/

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

/*--------------Exec Fonction---------------*/

int ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
	{
        std::cout << executor.getName() << " cannot execute " << this->getName() << " because his not signed\n";
		return 0;
	}
    else if (executor.getGrade() > this->getGradeToExecute())
	{
        std::cout << executor.getName() << " cannot execute " << this->getName() << " because his _grade is too low\n";
		return 0;
	}
	else
	{
		std::string shru = "_shrubbery";
		std::string name = this->getTarget() + shru;
		std::ofstream flux(name.c_str());
		if (flux)
		{
			flux << "\n\n";
			flux << "                                                         .\n";
			flux << "                                              .         ;  \n";
			flux << "                 .              .              ;%     ;;   \n";
			flux << "                   ,           ,                :;%  %;   \n";
			flux << "                    :         ;                   :;%;'     .,\n";   
			flux << "           ,.        %;     %;            ;        %;'    ,;\n";
			flux << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
			flux << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
			flux << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
			flux << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
			flux << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
			flux << "                    `:%;.  :;bd%;          %;@%;'\n";
			flux << "                      `@%:.  :;%.         ;@@%;'   \n";
			flux << "                        `@%.  `;@%.      ;@@%; \n";
			flux << "                          `@%%. `@%%    ;@@%;  \n";
			flux << "                            ;@%. :@%%  %@@%;   \n";
			flux << "                              %@bd%%%bd%%:;    \n";
			flux << "                                #@%%%%%:;;\n";
			flux << "                                %@@%%%::;\n";
			flux << "                                %@@@%(o);  . ' \n";
			flux << "                                %@@@o%;:(.,'   \n";
			flux << "                            `.. %@@@o%::;      \n";
			flux << "                               `)@@@o%::;      \n";
			flux << "                                %@@(o)::;      \n";
			flux << "                               .%@@@@%::;      \n";
			flux << "                               ;%@@@@%::;.     \n";
			flux << "                              ;%@@@@%%:;;;. \n";
			flux << "                          ...;%@@@@@%%:;;;;,.. \n";
			flux << "\n\n";
		}
		else
			std::cerr << "error flux\n";
	}
	return 1;
}