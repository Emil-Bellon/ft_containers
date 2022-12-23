NAME_FT_STACK = test_stack_ft
NAME_FT_VECTOR = test_vector_ft
NAME_FT_MAP = test_map_ft


NAME_STD_STACK = test_stack_std
NAME_STD_VECTOR = test_vector_std
NAME_STD_MAP = test_map_std

HEADERS_FILE = includes

HEADERS = \
			map.hpp \
			avl_tree.hpp \
			avl_node.hpp \
			stack.hpp \
			vector.hpp \
			utils.hpp \
			iterator_traits.hpp \
			iterator.hpp \

SRC_FT_MAP = srcs/main_map.cpp
SRC_FT_STACK = srcs/main_stack.cpp
SRC_FT_VECTOR = srcs/main_vector.cpp

SRC_STD_MAP = srcs/main_map_std.cpp
SRC_STD_STACK = srcs/main_stack_std.cpp
SRC_STD_VECTOR = srcs/main_vector_std.cpp

OBJ_FT_MAP = ${SRC_FT_MAP:.cpp=.o}
OBJ_FT_STACK = ${SRC_FT_STACK:.cpp=.o}
OBJ_FT_VECTOR = ${SRC_FT_VECTOR:.cpp=.o}

OBJ_STD_MAP = ${SRC_STD_MAP:.cpp=.o}
OBJ_STD_STACK = ${SRC_STD_STACK:.cpp=.o}
OBJ_STD_VECTOR = ${SRC_STD_VECTOR:.cpp=.o}


.PHONY: all clean fclean re 

all:  $(NAME_FT_MAP) $(NAME_FT_STACK)  $(NAME_FT_VECTOR) $(NAME_STD_MAP) $(NAME_STD_STACK)  $(NAME_STD_VECTOR) 

$(NAME_FT_MAP): $(OBJ_FT_MAP) $(HEADERS)
	clang++ $(OBJ_FT_MAP) -o $(NAME_FT_MAP)

$(NAME_FT_STACK): $(OBJ_FT_STACK) $(HEADERS)
	clang++ $(OBJ_FT_STACK) -o $(NAME_FT_STACK)

$(NAME_FT_VECTOR): $(OBJ_FT_VECTOR) $(HEADERS)
	clang++ $(OBJ_FT_VECTOR) -o $(NAME_FT_VECTOR)


$(NAME_STD_MAP): $(OBJ_STD_MAP) $(HEADERS)
	clang++ $(OBJ_STD_MAP) -o $(NAME_STD_MAP)

$(NAME_STD_STACK): $(OBJ_STD_STACK) $(HEADERS)
	clang++ $(OBJ_STD_STACK) -o $(NAME_STD_STACK)

$(NAME_STD_VECTOR): $(OBJ_STD_VECTOR) $(HEADERS)
	clang++ $(OBJ_STD_VECTOR) -o $(NAME_STD_VECTOR)




$(OBJ_FT_MAP): %.o: %.cpp $(HEADERS)
	clang++ -Wall -Wextra -Werror -std=c++98 -I$(HEADERS_FILE) -c $< -o $@

$(OBJ_FT_STACK): %.o: %.cpp $(HEADERS)
	clang++ -Wall -Wextra -Werror -std=c++98 -I$(HEADERS_FILE) -c $< -o $@

$(OBJ_FT_VECTOR): %.o: %.cpp $(HEADERS)
	clang++ -Wall -Wextra -Werror -std=c++98 -I$(HEADERS_FILE) -c $< -o $@


$(OBJ_STD_MAP): %.o: %.cpp $(HEADERS)
	clang++ -Wall -Wextra -Werror -std=c++98 -I$(HEADERS_FILE) -c $< -o $@

$(OBJ_STD_STACK): %.o: %.cpp $(HEADERS)
	clang++ -Wall -Wextra -Werror -std=c++98 -I$(HEADERS_FILE) -c $< -o $@

$(OBJ_STD_VECTOR): %.o: %.cpp $(HEADERS)
	clang++ -Wall -Wextra -Werror -std=c++98 -I$(HEADERS_FILE) -c $< -o $@


clean:
	rm -f $(OBJ_FT_STACK) $(OBJ_FT_VECTOR) $(OBJ_FT_MAP) $(OBJ_STD_STACK) $(OBJ_STD_VECTOR) $(OBJ_STD_MAP)

fclean: clean
	rm -f $(NAME_FT_STACK) $(NAME_FT_VECTOR) $(NAME_FT_MAP) $(NAME_STD_STACK) $(NAME_STD_VECTOR) $(NAME_STD_MAP)

re: fclean all