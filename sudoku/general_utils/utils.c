#include "sudoku.h"

void    print(int **tb, int order)
{
    int i = 0, j = 0;

    while(i < order * order)
    {
        j = 0;
        while(j < order * order)
        {
            printf("%d ", tb[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

void free_sudoku(t_sudoku *sudoku)
{
    int i;
    int size;

    if (!sudoku)
        return ;
    if (sudoku->tab)
    {
        size = sudoku->order * sudoku->order;
        i = 0;
        while (i < size)
        {
            free(sudoku->tab[i]);
            i++;
        }
        free(sudoku->tab);
    }
    free(sudoku);
}
