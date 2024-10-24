
# VAR ---------------------------------------------------------------
OBJS_DIR		=	.objs/
SRCS			=	srcs/Pair.cpp srcs/PmergeMe.cpp \
					srcs/utils/cast.cpp \
					srcs/utils/catoi.cpp \
					main.cpp
OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
DEP				=	$(addprefix $(OBJS_DIR), $(SRCS:.cpp=.d))

NAME			=	PmergeMe
HEAD			=	incs/

CC				=	c++
RM				=	rm -rf
FLAGS			=	-Wall -Wextra -Werror -std=c++98 -MMD -MP -fsanitize=address -g

# RULES -------------------------------------------------------------
all:				$(NAME)

run:				all
					./$(NAME) `jot -r 5000 1 10000 | tr '\n' ' '`

$(NAME):			$(OBJS)
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

-include $(DEP)
$(OBJS_DIR)%.o:		%.cpp
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)srcs
					@mkdir -p $(OBJS_DIR)srcs/utils
					$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@

clean:
					$(RM) $(OBJS_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all run clean fclean re
