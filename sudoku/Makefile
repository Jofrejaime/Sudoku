# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -Werror

# Executable name
NAME = sudoku

# Source files
SRCS = backtraking.c get_next_line.c main.c utils.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Compile executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compile .c to .o
%.o: %.c sudoku.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

# Run with map
run: $(NAME)
	./$(NAME) map1.txt