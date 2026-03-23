#include "sudoku.h"

int main(int argc, char *argv[])
{
    t_sudoku *sudoku;

    if (argc != 2)
    {
        printf("entrada invalida!\n");
        return (1);
    }
    sudoku = load_sudoku(argv[1]);
    if (!sudoku)
    {
        printf("invalid map!\n");
        return (1);
    }
    solve(sudoku->tab, sudoku->order);
    print(sudoku->tab, sudoku->order);
    free_sudoku(sudoku);
    return (0);
}
