#include "sudoku.h"

int main(int argc, char *argv[])
{
    t_sudoku *sudoku;

    if (argc != 2)
    {
        printf("entrada invalida!\n");
        return (1);
    }
    sudoku = validate(argv, argc);
    if (!sudoku)
    {
        printf("invalid map!\n");
        return (1);
    }

    print(sudoku->tab, sudoku->order);
}