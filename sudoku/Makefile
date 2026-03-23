CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

NAME = sudoku
OBJ_DIR = obj

SRCS = \
	main.c \
	backtracking/backtraking.c \
	utils/get_next_line.c \
	utils/utils.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: %.c sudoku.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(NAME).exe

re: fclean all

run: $(NAME)
	./$(NAME) map1.txt

.PHONY: all clean fclean re run

-include $(DEPS)