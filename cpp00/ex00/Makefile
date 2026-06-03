NAME		:= megaphone 
CXX			:= c++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98
SRC			:= megaphone.cpp
OBJ			:= $(SRC:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean flcean re
