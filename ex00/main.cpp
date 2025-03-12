#include "Bureaucrat.h"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main() {
    try {
        std::cout << BLUE "\nTesting default constructor:" RESET << std::endl;
        Bureaucrat b1;
        std::cout << &b1;

        std::cout << BLUE "\nTesting name constructor:" RESET << std::endl;
        Bureaucrat b2("Alice");
        std::cout << &b2;

        std::cout << BLUE "\nTesting grade constructor (valid case):" RESET << std::endl;
        Bureaucrat b3(42);
        std::cout << &b3;

        std::cout << BLUE "\nTesting name & grade constructor:" RESET << std::endl;
        Bureaucrat b4("Bob", 75);
        std::cout << &b4;

        std::cout << BLUE "\nTesting copy constructor:" RESET << std::endl;
        Bureaucrat b5(b4);
        std::cout << &b5;

        std::cout << BLUE "\nTesting assignment operator:" RESET << std::endl;
        Bureaucrat b6;
        b6 = b4;
        std::cout << &b6;

        std::cout << YELLOW "\nTesting incrementGrade() and decrementGrade():" RESET << std::endl;
        b4.incrementGrade();
        std::cout << &b4;
        b4.decrementGrade();
        std::cout << &b4;

        std::cout << RED "\nTesting exceptions (GradeTooHighException):" RESET << std::endl;
        Bureaucrat b7("Charlie", 1);
        b7.incrementGrade(); // Should throw an exception

    } catch (const std::exception& e) {
        std::cerr << RED "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << RED "\nTesting exceptions (GradeTooLowException):" RESET << std::endl;
        Bureaucrat b8("Dave", 150);
        b8.decrementGrade(); // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << RED "Exception caught: " << e.what() << RESET << std::endl;
    }
    
    try {
        std::cout << RED "\nTesting invalid grade on construction (too high):" RESET << std::endl;
        Bureaucrat b9("Eve", 0); // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << RED "Exception caught: " << e.what() << RESET << std::endl;
    }
    
    try {
        std::cout << RED "\nTesting invalid grade on construction (too low):" RESET << std::endl;
        Bureaucrat b10("Frank", 151); // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << RED "Exception caught: " << e.what() << RESET << std::endl;
    }
    
    return 0;
}
