NAME = Start

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

# The header file for your templates
HEADERS = Templates.hpp

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Explicitly track header dependencies for templates
main.o: main.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
