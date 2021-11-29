FT_NAME		= ft_containers
STD_NAME	= std_containers
OBJS		= $(SRCS:.cpp=.o)
FT			=	test/ft/vector/vector_constructor.cpp test/ft/vector/vector_iterator.cpp \
test/ft/vector/vector_capacity.cpp test/ft/vector/vector_access.cpp test/ft/vector/vector_assign.cpp \
test/ft/vector/vector_modifier.cpp test/ft/vector/vector_operators.cpp test/ft/stack/stack_tester.cpp \
test/ft/map/map_constructor.cpp test/ft/map/map_capacity.cpp test/ft/map/map_insert.cpp test/ft/map/map_modifier.cpp \
test/ft/map/map_observers.cpp test/ft/map/map_operations.cpp test/ft/map/map_iterator.cpp test/ft/map/map_operator.cpp main.cpp
STD			=	test/std/vector/std_vector_constructor.cpp test/std/vector/std_vector_iterator.cpp \
test/std/vector/std_vector_capacity.cpp test/std/vector/std_vector_access.cpp test/std/vector/std_vector_assign.cpp \
test/std/vector/std_vector_modifier.cpp test/std/vector/std_vector_operators.cpp test/std/stack/std_stack_tester.cpp \
test/std/map/std_map_constructor.cpp test/std/map/std_map_capacity.cpp test/std/map/std_map_insert.cpp test/std/map/std_map_modifier.cpp \
test/std/map/std_map_observers.cpp test/std/map/std_map_operations.cpp test/std/map/std_map_iterator.cpp test/std/map/std_map_operator.cpp main.cpp
SRCS		= $(FT) $(STD)

FLAGS		= -Wall -Werror -Wextra -I.
CC			= clang++

RM			= rm -f

%.o: %.cpp	includes/vector.hpp includes/VectorIterator.hpp includes/map.hpp includes/Utility.hpp includes/stack.hpp includes/Bst.hpp includes/BstIterator.hpp test/ft/test.hpp test/std/test.hpp includes/Iterator.hpp
			$(CC) $(FLAGS) -c $< -o $@

all:		$(FT_NAME)

$(FT_NAME):	$(FT:.cpp=.o)
			$(CC) $(FLAGS) -o $(FT_NAME) $(FT:.cpp=.o)

std:		$(STD:.cpp=.o)
			$(CC) $(FLAGS) -o $(STD_NAME) $(STD:.cpp=.o)

ft:			$(FT:.cpp=.o)
			$(CC) $(FLAGS) -o $(FT_NAME) $(FT:.cpp=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(FT_NAME) $(STD_NAME)

re:			fclean all

.PHONY:		all clean fclean re