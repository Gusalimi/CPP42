# ===== VARIABLES ===== #
NAME		= BraiiiiiiinnnzzzZ
SRCS		= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS		= $(SRCS:.cpp=.o)
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# ===== RULES ===== #
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
