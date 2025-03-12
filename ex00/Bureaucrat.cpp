#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(150) {
    std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat&src): _name(src._name + "(clone)") {
    std::cout << _name << " copy constructor called " << this->_grade << std::endl;
    *this = src;
}

Bureaucrat::Bureaucrat(const int grade): _name("default") {
    std::cout << _name << " grade constructor called " << grade << std::endl;
    this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string&name): _name(name), _grade(150) {
    std::cout << _name << " name constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string&name, const int grade): _name(name) {
    this->setGrade(grade);
    std::cout << _name << " name & grade constructor called " << this->_grade << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat&src) {
    std::cout << _name << " assignation operator called" << std::endl;
    if (this == &src) return *this;
    this->setGrade(src._grade);
    return *this;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << _name << " destructor called" << std::endl;
}

void Bureaucrat::incrementGrade() {
    std::cout << _name << " incrementing grade" << std::endl;
    setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade() {
    std::cout << _name << " decrementing grade" << std::endl;
    setGrade(this->_grade + 1);
}

std::string Bureaucrat::getName(void) const {
    return _name;
}

int Bureaucrat::getGrade(void) const {
    return _grade;
}

void Bureaucrat::setGrade(const int grade) {
    if (grade < 1) throw Bureaucrat::GradeTooHighException();
    else if (grade > 150) throw Bureaucrat::GradeTooLowException();
    else this->_grade = grade;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("grade too high");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat *a)
{
	o << a->getName() << ", bureaucrat grade " << a->getGrade() << std::endl;
	return (o);
}