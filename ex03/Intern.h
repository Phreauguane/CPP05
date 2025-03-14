#pragma once

#include "AForm.h"

class Intern
{
	private:
	public:
		Intern();
		Intern(const Intern &src);

		~Intern();

		Intern &operator=(const Intern &src);

		AForm *makeForm(const std::string &form, const std::string &target);
};