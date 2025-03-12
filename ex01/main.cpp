#include "Form.h"
#include "Bureaucrat.h"
#include <iostream>

int main() {
    try {
        std::cout << BLUE "\nTesting default constructor:" RESET << std::endl;
        Form f1;
        std::cout << &f1;

        std::cout << BLUE "\nTesting name constructor:" RESET << std::endl;
        Form f2("Tax Form");
        std::cout << &f2;

        std::cout << BLUE "\nTesting sign & exec grade constructor (valid case):" RESET << std::endl;
        Form f3(50, 25);
        std::cout << &f3;

        std::cout << BLUE "\nTesting full constructor (name, signGrade, execGrade):" RESET << std::endl;
        Form f4("Contract", 30, 20);
        std::cout << &f4;

        std::cout << BLUE "\nTesting copy constructor:" RESET << std::endl;
        Form f5(f4);
        std::cout << &f5;

        std::cout << BLUE "\nTesting assignment operator:" RESET << std::endl;
        Form f6;
        f6 = f4;
        std::cout << &f6;

        std::cout << YELLOW "\nTesting form signing by a Bureaucrat:" RESET << std::endl;
        Bureaucrat b1("Alice", 25);
        std::cout << &b1;
        f4.beSigned(b1);
        std::cout << &f4;

        std::cout << RED "\nTesting form signing with insufficient grade (should throw exception):" RESET << std::endl;
        Bureaucrat b2("Bob", 100);
        std::cout << &b2;
        f4.beSigned(b2);
    } catch (const std::exception& e) {
        std::cerr << RED "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << RED "\nTesting invalid form creation (signGrade too high):" RESET << std::endl;
        Form f7("Top Secret", 0, 10); // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << RED "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << RED "\nTesting invalid form creation (execGrade too low):" RESET << std::endl;
        Form f8("Public Notice", 50, 151); // Should throw an exception
    } catch (const std::exception& e) {
        std::cerr << RED "Exception caught: " << e.what() << RESET << std::endl;
    }
    
    return 0;
}
