CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone
SRC = megaphone.cpp
RM = rm -rf
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		  $(CC) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean :	clean
		$(RM) $(NAME)

re : fclean all