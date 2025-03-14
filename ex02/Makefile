NAME	=	forms

CPP		=	c++ -Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp					\
			AForm.cpp					\
			Bureaucrat.cpp				\
			ShrubberyCreationForm.cpp	\
			RobotomyRequestForm.cpp		\
			PresidentialPardonForm.cpp		\

all		:
	$(CPP) $(SRC) -o $(NAME)

clean	:
	rm -f $(NAME)

fclean	:	clean

re		:	fclean all