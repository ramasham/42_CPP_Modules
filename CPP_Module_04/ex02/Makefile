NAME = poly

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -I./include -std=c++98

SRC = src/main.cpp src/Animal.cpp src/Dog.cpp src/Cat.cpp \
	src/WrongAnimal.cpp src/WrongCat.cpp src/Brain.cpp
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