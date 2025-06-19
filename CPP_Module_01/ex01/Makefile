NAME = hordeZombie

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -I./include -std=c++98

SRC =  src/zombieHorde.cpp src/main.cpp src/Zombie.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re