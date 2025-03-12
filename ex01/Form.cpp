#include "Form.h"
#include "Bureaucrat.h"

Form::Form(void): _name("default"), _isSigned(false), _signGrade(150), _execGrade(150) {
    std::cout << "[Form] " << "constructor called []" << std::endl;
}

Form::Form(int sign, int exec): _name("default"), _isSigned(false), _signGrade(sign), _execGrade(exec) {
    std::cout << "[Form] " << "constructor called [signGrade: " << sign << ", execGrade: " << exec << "]" << std::endl;
    if (sign > 150 || exec > 150) throw Form::GradeTooLowException();
    if (sign < 1 || exec < 1) throw Form::GradeTooHighException();
}

Form::Form(const std::string& name): _name(name), _isSigned(false), _signGrade(150), _execGrade(150) {
    std::cout << "[Form] " << "constructor called [name: " << name << "]" << std::endl;
}

Form::Form(const std::string& name, int sign, int exec): _name(name), _isSigned(false), _signGrade(sign), _execGrade(exec) {
    std::cout << "[Form] " << "constructor called [name: " << name << ", signGrade: " << sign << ", execGrade: " << exec << "]" << std::endl;
    if (sign > 150 || exec > 150) throw Form::GradeTooLowException();
    if (sign < 1 || exec < 1) throw Form::GradeTooHighException();
}

Form::~Form(void) {
    std::cout << "[Form] " << _name << " destructor called" << std::endl;
}

Form &Form::operator=(const Form&src) {
    (void)src;
    std::cout << "[Form] " << "assignment operator called [name: " << _name << ", signGrade: " << _signGrade << ", execGrade: " << _execGrade << "]" << std::endl;
    return *this;
}

Form::Form(const Form&src): _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade) {
    std::cout << "[Form] " << "copy constructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat& signer) {
    if (signer.getGrade() > _signGrade) throw Bureaucrat::GradeTooLowException();
    else if (!_isSigned) {
        this->_isSigned = true;
        std::cout << GREEN "✓ " RESET << _name << " form succesfully signed by " << signer.getName() << std::endl;
    } else {
        std::cout << RED "✗ " RESET << _name << " form is already signed" << std::endl;
    }
}

const char *Form::GradeTooHighException::what(void) const throw() {
    return "grade too high";
}

const char *Form::GradeTooLowException::what(void) const throw() {
    return "grade too low";
}

std::ostream &operator<<(std::ostream &o, Form *a)
{
	o << "[Form] " << a->getName() <<
	"\n - signGrade:\t" << a->getSignGrade() <<
	"\n - execGrade:\t" << a->getExecGrade() <<
	"\n - isSigned:\t" << (a->getIsSigned() ? GREEN "✓ true" RESET : RED "✗ false" RESET) << std::endl;
	return (o);
}

std::string Form::getName(void) const {
    return _name;
}

bool Form::getIsSigned(void) const {
    return _isSigned;
}

int Form::getSignGrade(void) const {
    return _signGrade;
}

int Form::getExecGrade(void) const {
    return _execGrade;
}


