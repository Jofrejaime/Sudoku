CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

NAME = sudoku
OBJ_DIR = obj
MAP ?= maps/map4.txt

SRCS = \
	main.c \
	backtracking/backtracking.c \
	general_utils/get_next_line.c \
	general_utils/utils.c \
	validator/parser.c \
	validator/loader.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: %.c sudoku.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(NAME).exe

re: fclean all

run: $(NAME)
	./$(NAME) $(MAP)

run1: $(NAME)
	./$(NAME) maps/map1.txt

run2: $(NAME)
	./$(NAME) maps/map2.txt

run3: $(NAME)
	./$(NAME) maps/map3.txt

run4: $(NAME)
	./$(NAME) maps/map4.txt

.PHONY: all clean fclean re run run1 run2 run3 run4