NAME		= ft_containers
OBJS		= $(SRCS:.cpp=.o)
SRCS		= main.cpp test/vector/vector_constructor.cpp test/vector/vector_iterator.cpp test/vector/vector_capacity.cpp test/vector/vector_access.cpp test/vector/vector_assign.cpp test/vector/vector_modifier.cpp test/vector/vector_operators.cpp test/stack/stack_tester.cpp

FLAGS		= -Wall -Werror -Wextra -I.
CC			= clang++

RM			= rm -f

%.o: %.cpp	includes/vector.hpp includes/VectorIterator.hpp includes/map.hpp includes/Utility.hpp includes/stack.hpp includes/Bst.hpp includes/BstIterator.hpp test/test.hpp includes/Iterator.hpp
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