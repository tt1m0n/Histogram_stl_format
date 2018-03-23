CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

NAME = view

SRC = main.cpp print_errors.cpp read_facet.cpp read_facet_add.cpp\
      string_to_double.cpp initialize.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
