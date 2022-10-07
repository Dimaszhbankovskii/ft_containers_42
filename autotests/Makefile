NAME			=	autotest

CCXX			=	c++
CXXFLAGS		=	-Wall -Werror -Wextra -std=c++98
SANITIZE		=	-g3 -fsanitize=address

HEADER_DIR_FT	=	./../includes
HEADER_FT_LIST	=	vector.hpp \
					stack.hpp \
					iterator.hpp \
					type_traits.hpp
HEADER_FT		=	$(addprefix $(HEADER_DIR_FT)/,$(HEADER_FT_LIST))

HEADER_DIR_TEST	=	includes
HEADER_TEST		=	autotests.hpp
HEADER			=	$(addprefix $(HEADER_DIR_TEST)/,$(HEADER_TEST))

SRCS_DIR		=	srcs
SRCS_LIST		=	main.cpp \
					utils.cpp \
					vector.cpp
SRCS			=	$(addprefix $(SRCS_DIR)/,$(SRCS_LIST))

OBJS_DIR		=	objs
OBJS			=	$(addprefix $(OBJS_DIR)/,$(SRCS_LIST:.cpp=.o))

NORMAL			=	\033[0m
BOLD			=	\033[1m
UNDERLINE		=	\033[4m
BLACK			=	\033[1;30m
RED				=	\033[1;31m
GREEN			=	\033[1;32m
YELLOW			=	\033[1;33m
BLUE			=	\033[1;34m
VIOLET			=	\033[1;35m
CYAN			=	\033[1;36m
WHITE			=	\033[1;37m

all : $(OBJS_DIR) $(NAME)

$(NAME) : $(OBJS) $(HEADER_FT) $(HEADER) Makefile
	@$(CCXX) $(CXXFLAGS) $(SANITIZE) $(OBJS) -o $@
	@echo "$(GREEN)Project '$@' succesfully compiled$(NORMAL)"

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.cpp $(HEADER_FT) $(HEADER) Makefile
	@$(CCXX) $(CXXFLAGS) $(SANITIZE) -c $< -o $@
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR) :
	@mkdir -p objs
	@echo "$(CYAN)Creating directory for objects file$(WHITE) --> $@ --> $(GREEN)[Done]$(NORMAL)"	

# ./srcs/%.o: ./srcs/%.cpp
# 	c++ ${CXXFLAGS} -c $< -o $@

# vector: ${NAME}
# 	./${NAME} vector

# list: ${NAME}
# 	./${NAME} list

# map: ${NAME}
# 	./${NAME} map

# stack: ${NAME}
# 	./${NAME} stack

# queue: ${NAME}
# 	./${NAME} queue

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(VIOLET)Removing objects files$(WHITE) --> *.o --> $(GREEN)[Done]$(NORMAL)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(VIOLET)Removing perfoming file$(WHITE) --> $(NAME) --> $(GREEN)[Done]$(NORMAL)"

re: fclean all

.PHONY: all clean fclean re