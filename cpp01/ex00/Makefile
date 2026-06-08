NAME			:= ex00

CXX				:= c++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98

SRC				:= Zombie.cpp \
						 newZombie.cpp \
						 randomChump.cpp \
						 main.cpp
OBJ				:= $(SRC:.cpp=.o)

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

.PHONY: all clean fclean re
