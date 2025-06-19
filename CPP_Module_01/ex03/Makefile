NAME = violence

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -I./include -std=c++98

SRC = src/main.cpp src/HumanA.cpp src/HumanB.cpp src/weapon.cpp
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