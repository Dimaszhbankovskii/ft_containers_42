NAME_STD_LIST		=	std_list
NAME_FT_LIST		=	ft_list

CCXX				=	c++
CXXFLAGS			=	-Wall -Werror -Wextra -std=c++98

HEADER_DIR			=	./../../includes
HEADER_FT_LIST		=	list.hpp \
						iterator.hpp
HEADER				=	$(addprefix $(HEADER_DIR)/,$(HEADER_FT_LIST))

DIR_STD_LIST		=	srcs_std_list

HEADER_STD_LIST		=	std_list.hpp

SRCS_STD_LIST_LIST	=	main_std_list.cpp \
						test_std_list_1.cpp
SRCS_STD_LIST		=	$(addprefix $(DIR_STD_LIST)/,$(SRCS_STD_LIST_LIST))

DIR_FT_LIST			=	srcs_ft_list

HEADER_FT_LIST_TEST	=	ft_list.hpp

SRCS_FT_LIST_LIST	=	main_ft_list.cpp \
						test_ft_list_1.cpp
SRCS_FT_LIST		=	$(addprefix $(DIR_FT_LIST)/,$(SRCS_FT_LIST_LIST))

OBJS_DIR			=	objs

OBJS_STD_LIST		=	$(addprefix $(OBJS_DIR)/,$(SRCS_STD_LIST_LIST:.cpp=.o))
OBJS_FT_LIST		=	$(addprefix $(OBJS_DIR)/,$(SRCS_FT_LIST_LIST:.cpp=.o))

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

all : $(OBJS_DIR) $(NAME_STD_LIST) $(NAME_FT_LIST)

$(NAME_STD_LIST) : $(OBJS_STD_LIST) $(DIR_STD_LIST)/$(HEADER_STD_LIST) Makefile
	@$(CCXX) $(CXXFLAGS) $(OBJS_STD_LIST) -o $@
	@echo "$(GREEN)Project '$@' succesfully compiled$(NORMAL)"

$(OBJS_DIR)/%.o : $(DIR_STD_LIST)/%.cpp $(DIR_STD_LIST)/$(HEADER_STD_LIST) Makefile
	@$(CCXX) $(CXXFLAGS) -O3 -c $< -o $@
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(NAME_FT_LIST) : $(OBJS_FT_LIST) $(DIR_FT_LIST)/$(HEADER_FT_LIST_TEST) Makefile
	@$(CCXX) $(CXXFLAGS) $(OBJS_FT_LIST) -o $@
	@echo "$(GREEN)Project '$@' succesfully compiled$(NORMAL)"

$(OBJS_DIR)/%.o : $(DIR_FT_LIST)/%.cpp $(DIR_FT_LIST)/$(HEADER_FT_LIST_TEST) Makefile
	@$(CCXX) $(CXXFLAGS) -O3 -c $< -o $@
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR) :
	@mkdir -p objs
	@echo "$(CYAN)Creating directory for objects file$(WHITE) --> $@ --> $(GREEN)[Done]$(NORMAL)"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "$(VIOLET)Removing objects files$(WHITE) --> *.o --> $(GREEN)[Done]$(NORMAL)"

fclean : clean
	@rm -rf $(NAME_STD_LIST) $(NAME_FT_LIST)
	@echo "$(VIOLET)Removing perfoming file$(WHITE) --> $(NAME_STD_LIST) --> $(GREEN)[Done]$(NORMAL)"
	@echo "$(VIOLET)Removing perfoming file$(WHITE) --> $(NAME_FT_LIST) --> $(GREEN)[Done]$(NORMAL)"

re : fclean all

.PHONY: all clean fclean re
