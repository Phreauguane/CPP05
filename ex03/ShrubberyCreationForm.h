#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.h"
#include "AForm.h"

class Bureaucrat;

class AForm;

class ShrubberyCreationForm: public AForm
{
private:
    const std::string _target;
    ShrubberyCreationForm(void);
public:
    ShrubberyCreationForm(std::string);
    ShrubberyCreationForm(ShrubberyCreationForm&);

    ~ShrubberyCreationForm(void);

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);

    void execute(const Bureaucrat&)const;
    std::string getTarget(void)const;
};

std::ostream &operator<<(std::ostream&, ShrubberyCreationForm*);