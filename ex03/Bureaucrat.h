#pragma once

#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
public:
    Bureaucrat(void); //
    Bureaucrat(const int); //
    Bureaucrat(const std::string&); //
    Bureaucrat(const std::string&, const int); //
    Bureaucrat(const Bureaucrat&); //

    std::string getName(void) const;
    int getGrade(void) const;

    void incrementGrade(void);
    void decrementGrade(void);
    
    ~Bureaucrat();

    void signForm(AForm&);
    void executeForm(AForm&);

    Bureaucrat& operator=(const Bureaucrat&);
    
	class GradeTooLowException : public std::exception
	{
        public:
            virtual const char *what(void) const throw();
	};

	class GradeTooHighException : public std::exception
	{
        public:
            virtual const char *what(void) const throw();
	};
private:
    const std::string _name;
    size_t _grade;

    void setGrade(const int);
};

std::ostream &operator<<(std::ostream &, Bureaucrat *);