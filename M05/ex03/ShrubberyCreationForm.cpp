#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("shrubbery creation", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("shrubbery creation", 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& b): Form(b)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	this->_target = b._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	this->_target = rhs._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	ofs;
	std::string tree = "                                              .\n\
                                   .         ;\n\
      .              .              ;%     ;;\n\
        ,           ,                :;%  %;\n\
         :         ;                   :;%;'     .,\n\
,.        %;     %;            ;        %;'    ,;\n\
  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
   %;       %;%;      ,  ;       %;  ;%;   ,%;'\n\
    ;%;      %;        ;%;        % ;%;  ,%;'\n\
     `%;.     ;%;     %;'         `;%%;.%;'\n\
      `:;%.    ;%%. %@;        %; ;@%;%'\n\
         `:%;.  :;bd%;          %;@%;'\n\
           `@%:.  :;%.         ;@@%;'\n\
             `@%.  `;@%.      ;@@%;\n\
               `@%%. `@%%    ;@@%;\n\
                 ;@%. :@%%  %@@%;\n\
                   %@bd%%%bd%%:;\n\
                     #@%%%%%:;;\n\
                     %@@%%%::;\n\
                     %@@@%(o);  . '\n\
                     %@@@o%;:(.,'\n\
                 `.. %@@@o%::;\n\
                    `)@@@o%::;\n\
                     %@@(o)::;\n\
                    .%@@@@%::;\n\
                    ;%@@@@%::;.\n\
                   ;%@@@@%%:;;;.\n\
               ...;%@@@@@%%:;;;;,..";
 	if (executor.getGrade() > this->Form::getGradeToExecute())
		throw Form::GradeTooLowException();
	else if (!this->Form::isSigned())
		throw std::exception();
	else
	{
		ofs.open(this->_target + "_shrubbery");
		if (ofs.fail())
		{
			std::cerr << "Can't open " << this->_target << "_shrubbery for writing" << std::endl;
			return ;
		}
		ofs << tree << std::endl;
	}
}