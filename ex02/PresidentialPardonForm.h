#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.h"
#include "AForm.h"

class Bureaucrat;
class AForm;

class PresidentialPardonForm: public AForm {
    private:
        const std::string _target;
        PresidentialPardonForm(void);
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm&);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(const PresidentialPardonForm&);

        void execute(const Bureaucrat&) const;

        std::string getTarget(void) const;
};

std::ostream &operator<<(std::ostream&, PresidentialPardonForm*);