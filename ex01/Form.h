#pragma once

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class Bureaucrat;

class Form
{
public:
    Form(void); //
    Form(int, int); //
    Form(const std::string&); //
    Form(const std::string&, int, int); //
    Form(const Form&);

    ~Form();

    Form& operator=(const Form&);

    void beSigned(const Bureaucrat&);

    std::string getName(void) const;
    bool getIsSigned(void) const;
    int getSignGrade(void) const;
    int getExecGrade(void) const;

    class GradeTooLowException: public std::exception 
    {
	    public:
            virtual const char *what(void) const throw();
    };

    class GradeTooHighException: public std::exception 
    {
	    public:
            virtual const char *what(void) const throw();
    };

private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;
};

std::ostream &operator<<(std::ostream &o, Form *a);