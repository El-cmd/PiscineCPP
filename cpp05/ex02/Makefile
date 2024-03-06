CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = BuroThree

SRC = Bureaucrat.cpp \
      AForm.cpp \
	  ShrubberyCreationForm.cpp \
	  RobotomyRequestForm.cpp \
	  PresidentialPardonForm.cpp \
	  main.cpp

RM = rm -rf
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		  $(CC) $(OBJ) -o $(NAME)
		  @printf "\e[92;5;118m\n>>> Executable ready\n\e[0m"

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	@printf "\033[00;31m\n>>> Object files removed.\n\033[00m"
	$(RM) $(OBJ)

fclean :	clean
		@printf "\033[00;31m\n>>> Executable removed.\n\033[00m"
		$(RM) $(NAME)

re : fclean all