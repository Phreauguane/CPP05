
#include "Intern.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

Intern::Intern() {
    std::cout << "[Intern] constructor called" << std::endl;
}

Intern::Intern(const Intern &src) {
    std::cout << "[Intern] copy constructor called" << std::endl;
    (void)src;
}

Intern::~Intern() {
    std::cout << "[Intern] destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src) {
    std::cout << "[Intern] assignation operator called" << std::endl;
    (void)src;
    return *this;
}

static AForm *makePres(const std::string &target) {
    return new PresidentialPardonForm(target);
}

static AForm *makeRob(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm *makeShrub(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &form, const std::string &target) {
	AForm *(*all_forms[])(const std::string &target) = {&makePres, &makeRob, &makeShrub};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

    for (int i = 0; i < 3; ++i)
    {
        if (form == forms[i]) {
			std::cout << "[Intern] creating " << form << std::endl;
			return (all_forms[i](target));
        }
    }
    
	std::cout << RED "[Intern] cannot create a form called " << form << RESET << std::endl;
	return (NULL);
}