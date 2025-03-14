#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.h"
#include "AForm.h"

class Bureaucrat;
class AForm;

class RobotomyRequestForm: public AForm {
    private:
        const std::string _target;
        RobotomyRequestForm(void);
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm&);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm&);

        void execute(const Bureaucrat&) const;

        std::string getTarget(void) const;
};

std::ostream &operator<<(std::ostream&, RobotomyRequestForm*);