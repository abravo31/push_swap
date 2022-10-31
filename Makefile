NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
		check_stack.c stack.c tools.c \
		push.c reverse_rotate.c rotate.c swap.c \
		sort_tiny.c cost.c move.c position.c sort.c \

SRCS_DIR = srcs

OBJDIR = objs/

OBJ = ${patsubst %.c,${OBJDIR}/%.o,${SRC}}

all: $(NAME)

$(NAME) : $(OBJDIR) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[32m$ ${NAME} compiled !"
	@echo "----------------------------\033[0m"

$(OBJDIR):
	@mkdir -p ${OBJDIR}
	@echo "\033[33mCompiling ${NAME}..."

${OBJDIR}/%.o: ${SRCS_DIR}/%.c
	@${CC} ${CFLAGS} -I. -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "\033[32mClean !\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
