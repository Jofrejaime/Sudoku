#ifndef SUDOKU_H
# define SUDOKU_H
   #define BUFFER_SIZE 42

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_sudoku
{
    int **tab;
    int order;
}   t_sudoku;


char *get_next_line(int fd);
t_sudoku    *validate(char **argv, int argc);
void    print(int **tb, int order);
void    solve(int **tb, int order);

#endif