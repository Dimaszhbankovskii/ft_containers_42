NAME_STD_VECTOR		=	std_vector
NAME_FT_VECTOR		=	ft_vector

CCXX				=	c++
CXXFLAGS			=	-Wall -Werror -Wextra -std=c++98

HEADER_DIR			=	./../../includes
HEADER_FT_VECTOR	=	vector.hpp \
						iterator.hpp
HEADER				=	$(addprefix $(HEADER_DIR)/,$(HEADER_FT_VECTOR))

DIR_STD_VECTOR			=	srcs_std_vector

HEADER_STD_VECTOR		=	std_vector.hpp

SRCS_STD_VECTOR_LIST	=	main_std_vector.cpp \
							test_std_iterator_1.cpp \
							test_std_iterator_2.cpp \
							test_std_reverse_iterator_1.cpp \
							test_std_reverse_iterator_2.cpp \
							test_std_vector_1.cpp \
							test_std_vector_1_element_access.cpp \
							test_std_vector_1_iterators.cpp \
							test_std_vector_1_capacity.cpp
SRCS_STD_VECTOR			=	$(addprefix $(DIR_STD_VECTOR)/,$(SRCS_STD_VECTOR_LIST))

DIR_FT_VECTOR			=	srcs_ft_vector

HEADER_FT_VECTOR		=	ft_vector.hpp

SRCS_FT_VECTOR_LIST		=	main_ft_vector.cpp \
							test_ft_iterator_1.cpp \
							test_ft_iterator_2.cpp \
							test_ft_reverse_iterator_1.cpp \
							test_ft_reverse_iterator_2.cpp \
							test_ft_vector_1.cpp \
							test_ft_vector_1_element_access.cpp \
							test_ft_vector_1_iterators.cpp \
							test_ft_vector_1_capacity.cpp
SRCS_FT_VECTOR			=	$(addprefix $(DIR_FT_VECTOR)/,$(SRCS_FT_VECTOR_LIST))


OBJS_DIR			=	objs

OBJS_STD_VECTOR		=	$(addprefix $(OBJS_DIR)/,$(SRCS_STD_VECTOR_LIST:.cpp=.o))
OBJS_FT_VECTOR		=	$(addprefix $(OBJS_DIR)/,$(SRCS_FT_VECTOR_LIST:.cpp=.o))

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

all : $(OBJS_DIR) $(NAME_STD_VECTOR) $(NAME_FT_VECTOR)

$(NAME_STD_VECTOR) : $(OBJS_STD_VECTOR) $(DIR_STD_VECTOR)/$(HEADER_STD_VECTOR) Makefile
	@$(CCXX) $(CXXFLAGS) $(OBJS_STD_VECTOR) -o $@
	@echo "$(GREEN)Project '$@' succesfully compiled$(NORMAL)"

$(OBJS_DIR)/%.o : $(DIR_STD_VECTOR)/%.cpp $(DIR_STD_VECTOR)/$(HEADER_STD_VECTOR) Makefile
	@$(CCXX) $(CXXFLAGS) -O3 -c $< -o $@
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(NAME_FT_VECTOR) : $(OBJS_FT_VECTOR) $(DIR_FT_VECTOR)/$(HEADER_FT_VECTOR) Makefile
	@$(CCXX) $(CXXFLAGS) $(OBJS_FT_VECTOR) -o $@
	@echo "$(GREEN)Project '$@' succesfully compiled$(NORMAL)"

$(OBJS_DIR)/%.o : $(DIR_FT_VECTOR)/%.cpp $(DIR_FT_VECTOR)/$(HEADER_FT_VECTOR) Makefile
	@$(CCXX) $(CXXFLAGS) -O3 -c $< -o $@
	@echo "$(BLUE)Creating object file$(WHITE) --> $(notdir $@) --> $(GREEN)[Done]$(NORMAL)"

$(OBJS_DIR) :
	@mkdir -p objs
	@echo "$(CYAN)Creating directory for objects file$(WHITE) --> $@ --> $(GREEN)[Done]$(NORMAL)"

clean :
	@rm -rf $(OBJS_DIR)
	@echo "$(VIOLET)Removing objects files$(WHITE) --> *.o --> $(GREEN)[Done]$(NORMAL)"

fclean : clean
	@rm -rf $(NAME_STD_VECTOR) $(NAME_FT_VECTOR)
	@echo "$(VIOLET)Removing perfoming file$(WHITE) --> $(NAME_STD_VECTOR) --> $(GREEN)[Done]$(NORMAL)"
	@echo "$(VIOLET)Removing perfoming file$(WHITE) --> $(NAME_FT_VECTOR) --> $(GREEN)[Done]$(NORMAL)"

re : fclean all

.PHONY: all clean fclean re
