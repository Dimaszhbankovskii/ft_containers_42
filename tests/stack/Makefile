NAME_STD_STACK		=	std_stack
NAME_FT_STACK		=	ft_stack

CCXX				=	c++
CXXFLAGS			=	-Wall -Werror -Wextra -std=c++98

HEADER_DIR			=	./../../includes
HEADER_FT_STACK		=	stack.hpp
HEADER				=	$(addprefix $(HEADER_DIR)/,$(HEADER_FT_STACK))

DIR_STD_STACK		=	srcs_std_stack

SRCS_STD_STACK_LIST	=	main_std_stack.cpp
SRCS_STD_STACK		=	$(addprefix $(DIR_STD_STACK)/,$(SRCS_STD_STACK_LIST))

DIR_FT_STACK		=	srcs_ft_stack

SRCS_FT_STACK_LIST	=	main_ft_stack.cpp
SRCS_FT_STACK		=	$(addprefix $(DIR_FT_STACK)/,$(SRCS_FT_STACK_LIST))

OBJS_DIR			=	objs

OBJS_STD_STACK		=	$(addprefix $(OBJS_DIR)/,$(SRCS_STD_STACK_LIST:.cpp=.o))
OBJS_FT_STACK		=	$(addprefix $(OBJS_DIR)/,$(SRCS_FT_STACK_LIST:.cpp=.o))

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

all : $(OBJS_DIR) $(NAME_STD_STACK) $(NAME_FT_STACK)

$(NAME_STD_STACK) : $(OBJS_STD_STACK) Makefile
	@$(CCXX) $(CXXFLAGS) $(OBJS_STD_STACK) -o $@
	@echo "$(GREEN)Project '$@' succesfully compiled$(NORMAL)"

$(OBJS_DIR)/%.o : $(DIR_STD_STACK)/%.cpp Makefile
	@$(CCXX) $(CXXFLAGS) -O3 -c $< -o $@
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(NAME_FT_STACK) : $(OBJS_FT_STACK) Makefile
	@$(CCXX) $(CXXFLAGS) $(OBJS_FT_STACK) -o $@
	@echo "$(GREEN)Project '$@' succesfully compiled$(NORMAL)"

$(OBJS_DIR)/%.o : $(DIR_FT_STACK)/%.cpp Makefile
	@$(CCXX) $(CXXFLAGS) -O3 -c $< -o $@
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR) :
	@mkdir -p objs
	@echo "$(CYAN)Creating directory for objects file$(WHITE) --> $@ --> $(GREEN)[Done]$(NORMAL)"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "$(VIOLET)Removing objects files$(WHITE) --> *.o --> $(GREEN)[Done]$(NORMAL)"

fclean : clean
	@rm -rf $(NAME_STD_STACK) $(NAME_FT_STACK)
	@echo "$(VIOLET)Removing perfoming file$(WHITE) --> $(NAME_STD_STACK) --> $(GREEN)[Done]$(NORMAL)"
	@echo "$(VIOLET)Removing perfoming file$(WHITE) --> $(NAME_FT_STACK) --> $(GREEN)[Done]$(NORMAL)"

re : fclean all

.PHONY: all clean fclean re
