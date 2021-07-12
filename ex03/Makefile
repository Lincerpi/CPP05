# -*- MakeFile -*-

NAME	= ex03

SRCS	=	Bureaucrat.cpp \
			Form.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationFormm.cpp \
			Intern.cpp \
			main.cpp

CC		= clang++

CFLAGS	= -Wall -Wextra -Werror

all:
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
		rm -rf $(NAME)

fclean: clean

re: 	clean all

.PHONY: all clean fclean re