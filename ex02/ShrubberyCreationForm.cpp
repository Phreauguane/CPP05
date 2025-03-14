
#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137), _target("default") {
    std::cout << "[ShrubberyCreationForm] constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "[ShrubberyCreationForm] constructor called [target: " + _target + "]" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src): AForm("ShrubberyCreationForm", 145, 137), _target(src.getTarget()) {
    std::cout << "[ShrubberyCreationForm] copy constructor called [target: " + _target + "]" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "[ShrubberyCreationForm] destructor called [target: " + _target + "]" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	std::cout << "[ShrubberyCreationForm] assignation operator called" << std::endl;
    (void)src;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    std::string tree = "\
     ___________________________________________________________ \n\
    |                                                      .    |\n\
    |                                       .         ;         |\n\
    |          .              .              ;%     ;;          |\n\
    |            ,           ,                :;%  %;           |\n\
    |             :         ;                   :;%;'     .,    |\n\
    |    ,.        %;     %;            ;        %;'    ,;      |\n\
    |      ;       ;%;  %%;        ,     %;    ;%;    ,%'       |\n\
    |       %;       %;%;      ,  ;       %;  ;%;   ,%;'        |\n\
    |        ;%;      %;        ;%;        % ;%;  ,%;'          |\n\
    |         `%;.     ;%;     %;'         `;%%;.%;'            |\n\
    |          `:;%.    ;%%. %@;        %; ;@%;%'               |\n\
    |             `:%;.  :;bd%;          %;@%;'                 |\n\
    |               `@%:.  :;%.         ;@@%;'                  |\n\
    |                 `@%.  `;@%.      ;@@%;                    |\n\
    |                   `@%%. `@%%    ;@@%;                     |\n\
    |                     ;@%. :@%%  %@@%;                      |\n\
    |                       %@bd%%%bd%%:;                       |\n\
    |                         #@%%%%%:;;                        |\n\
    |                         %@@%%%::;                         |\n\
    |                         %@@@%(o);  . '                    |\n\
    |                         %@@@o%;:(.,'                      |\n\
    |   _                 `.. %@@@o%::;                         |\n\
    |  | |                   `)@@@o%::;                         |\n\
    |  | |_ _ __ ___  ___     %@@(o)::;                         |\n\
    |  | __| '__/ _ \\/ _ \\   .%@@@@%::;                         |\n\
    |  | |_| | |  __/  __/   ;%@@@@%::;.                        |\n\
    |   \\__|_|  \\___|\\___|  ;%@@@@%%:;;;.                       |\n\
    |___________________...;%@@@@@%%:;;;;,..____________________|\n\n";
    
    if ((int)executor.getGrade() > this->getExecGrade())
        throw (Bureaucrat::GradeTooLowException());
    else if (!(this->getIsSigned()))
        throw (AForm::FormNotSignedException());
    else {
        std::ofstream outfile((_target + "_shrubbery").c_str());
        
        for (int i = 0; i < 60; i++)
        {
            outfile << tree << std::endl;
        }
        outfile.close();
        std::cout << executor.getName() + " executed " + this->getName() + " with target " + _target << std::endl;
        std::cout << "[Result outputed to file \"" + (_target + "_shrubbery") + "\"]" << std::endl;
    }

}

std::string	ShrubberyCreationForm::getTarget(void) const {
	return (this->_target);
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
	o << "[ShrubberyCreationForm] " << a->getName() <<
	"\n - signGrade\t:\t" << a->getSignGrade() <<
	"\n - execGrade\t:\t" << a->getExecGrade() <<
	"\n - isSigned\t:\t" << (a->getIsSigned() ? GREEN "✓ true" RESET : RED "✗ false" RESET) << 
    "\n - target\t:\t" << a->getTarget() << std::endl;
	return (o);
}