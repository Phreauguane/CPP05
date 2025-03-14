#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void testForm(AForm &form, Bureaucrat &highRank, Bureaucrat &lowRank) {
    std::cout << CYAN "\n[Testing Form: " << form.getName() << "]" RESET << std::endl;

    std::cout << YELLOW "Attempting to execute without signing..." RESET << std::endl;
    try {
        form.execute(highRank);
    } catch (const std::exception &e) {
        std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << GREEN "Signing the form..." RESET << std::endl;
    try {
        highRank.signForm(form);
    } catch (const std::exception &e) {
        std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW "Attempting to execute with insufficient grade..." RESET << std::endl;
    try {
        form.execute(lowRank);
    } catch (const std::exception &e) {
        std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << GREEN "Executing with a high-rank bureaucrat..." RESET << std::endl;
    try {
        form.execute(highRank);
    } catch (const std::exception &e) {
        std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
    }
}

int main() {
    std::cout << BLUE "\n=== Bureaucracy System Test ===" RESET << std::endl;

    Bureaucrat highRank("Alice", 1);
    Bureaucrat lowRank("Bob", 150);

    PresidentialPardonForm pForm("Target A");
    RobotomyRequestForm rForm("Target B");
    ShrubberyCreationForm sForm("Target C");

    testForm(pForm, highRank, lowRank);
    testForm(rForm, highRank, lowRank);
    testForm(sForm, highRank, lowRank);

    return 0;
}
