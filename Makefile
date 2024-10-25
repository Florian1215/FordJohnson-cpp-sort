
# VAR ------------------------------------------------------------------------ #
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
FLAGS			=	-Wall -Wextra -Werror -std=c++98 -MMD -MP

RANGE			=	1000
NUMBERS			=	3000

UNAME			=	$(shell uname -s)

ifeq ($(UNAME), Linux)
CMD				=	`shuf -i 1-$(RANGE) -n $(NUMBERS) | tr '\n' ' '`
endif

ifeq ($(UNAME), Darwin)
CMD				=	`jot -r $(NUMBERS) 1 $(RANGE) | tr '\n' ' '`
endif

# RULES ---------------------------------------------------------------------- #
all:				$(NAME)

run:				all
					./$(NAME) $(CMD)

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
