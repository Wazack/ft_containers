NAME		= in_progress
OBJS		= $(SRCS:.cpp=.o)
SRCS		= main.cpp

FLAGS		= -Wall -Werror -Wextra -I.
CC			= clang++

RM			= rm -f

%.o: %.cpp	includes/Vector.hpp
			$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re