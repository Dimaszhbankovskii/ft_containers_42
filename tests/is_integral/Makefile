NAME_STD_IS_INTEGRAL	=	std_is_integral
NAME_FT_IS_INTEGRAL		=	ft_is_integral

CCXX					=	c++
CXXFLAGS				=	-Wall -Werror -Wextra -std=c++11

HEADER_DIR				=	./../../includes
HEADER_FT_IS_INTEGRAL	=	type_traits.hpp
HEADER					=	$(addprefix $(HEADER_DIR)/,$(HEADER_FT_IS_INTEGRAL))

DIR_STD_IS_INTEGRAL			=	srcs_std_is_integral
SRCS_STD_IS_INTEGRAL_LIST	=	main_std_is_integral.cpp
SRCS_STD_IS_INTEGRAL		=	$(addprefix $(DIR_STD_IS_INTEGRAL)/,$(SRCS_STD_IS_INTEGRAL_LIST))

DIR_FT_IS_INTEGRAL			=	srcs_ft_is_integral
SRCS_FT_IS_INTEGRAL_LIST	=	main_ft_is_integral.cpp
SRCS_FT_IS_INTEGRAL			=	$(addprefix $(DIR_FT_IS_INTEGRAL)/,$(SRCS_FT_IS_INTEGRAL_LIST))

OBJS_DIR					=	objs

OBJS_STD_IS_INTEGRAL		=	$(addprefix $(OBJS_DIR)/,$(SRCS_STD_IS_INTEGRAL_LIST:.cpp=.o))
OBJS_FT_IS_INTEGRAL			=	$(addprefix $(OBJS_DIR)/,$(SRCS_FT_IS_INTEGRAL_LIST:.cpp=.o))

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

all : $(OBJS_DIR) $(NAME_STD_IS_INTEGRAL) $(NAME_FT_IS_INTEGRAL)

$(NAME_STD_IS_INTEGRAL) : $(OBJS_STD_IS_INTEGRAL) Makefile
	@$(CCXX) $(CXXFLAGS) $(OBJS_STD_IS_INTEGRAL) -o $@
	@echo "$(GREEN)Project '$@' succesfully compiled$(NORMAL)"

$(OBJS_DIR)/%.o : $(DIR_STD_IS_INTEGRAL)/%.cpp Makefile
	@$(CCXX) $(CXXFLAGS) -O3 -c $< -o $@
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(NAME_FT_IS_INTEGRAL) : $(OBJS_FT_IS_INTEGRAL) Makefile
	@$(CCXX) $(CXXFLAGS) $(OBJS_FT_IS_INTEGRAL) -o $@
	@echo "$(GREEN)Project '$@' succesfully compiled$(NORMAL)"

$(OBJS_DIR)/%.o : $(DIR_FT_IS_INTEGRAL)/%.cpp Makefile
	@$(CCXX) $(CXXFLAGS) -O3 -c $< -o $@
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR) :
	@mkdir -p objs
	@echo "$(CYAN)Creating directory for objects file$(WHITE) --> $@ --> $(GREEN)[Done]$(NORMAL)"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "$(VIOLET)Removing objects files$(WHITE) --> *.o --> $(GREEN)[Done]$(NORMAL)"

fclean : clean
	@rm -rf $(NAME_STD_IS_INTEGRAL) $(NAME_FT_IS_INTEGRAL)
	@echo "$(VIOLET)Removing perfoming file$(WHITE) --> $(NAME_STD_IS_INTEGRAL) --> $(GREEN)[Done]$(NORMAL)"
	@echo "$(VIOLET)Removing perfoming file$(WHITE) --> $(NAME_FT_IS_INTEGRAL) --> $(GREEN)[Done]$(NORMAL)"

re : fclean all

.PHONY: all clean fclean re
