#include "sudoku.h"

static int  board_size(int order)
{
    return (order * order);
}

static unsigned long long full_mask(int size)
{
    if (size >= 64)
        return (~0ULL);
    return ((1ULL << size) - 1ULL);
}

static void mark_row_used(int **tb, int size, int row, unsigned long long *used)
{
    int col;

    col = 0;
    while (col < size)
    {
        if (tb[row][col] > 0)
            *used |= (1ULL << (tb[row][col] - 1));
        col++;
    }
}

static void mark_col_used(int **tb, int size, int col, unsigned long long *used)
{
    int row;

    row = 0;
    while (row < size)
    {
        if (tb[row][col] > 0)
            *used |= (1ULL << (tb[row][col] - 1));
        row++;
    }
}

static void mark_box_used(int **tb, int order, int row, int col,
    unsigned long long *used)
{
    int start_row;
    int start_col;
    int r;
    int c;

    start_row = (row / order) * order;
    start_col = (col / order) * order;
    r = start_row;
    while (r < start_row + order)
    {
        c = start_col;
        while (c < start_col + order)
        {
            if (tb[r][c] > 0)
                *used |= (1ULL << (tb[r][c] - 1));
            c++;
        }
        r++;
    }
}

static unsigned long long get_possible(int **tb, int order, int row, int col)
{
    int                 size;
    unsigned long long  used;

    size = board_size(order);
    used = 0;
    mark_row_used(tb, size, row, &used);
    mark_col_used(tb, size, col, &used);
    mark_box_used(tb, order, row, col, &used);
    return (~used & full_mask(size));
}

static int count_bits(unsigned long long mask)
{
    int count;

    count = 0;
    while (mask)
    {
        if (mask & 1ULL)
            count++;
        mask >>= 1;
    }
    return (count);
}

static int find_best_cell(int **tb, int order, int *best_row, int *best_col,
    unsigned long long *best_mask)
{
    int                 size;
    int                 min_options;
    int                 row;
    int                 col;
    unsigned long long  possible;
    int                 count;

    size = board_size(order);
    min_options = size + 1;
    row = 0;
    while (row < size)
    {
        col = 0;
        while (col < size)
        {
            if (tb[row][col] == 0)
            {
                possible = get_possible(tb, order, row, col);
                count = count_bits(possible);
                if (count == 0)
                    return (-1);
                if (count < min_options)
                {
                    min_options = count;
                    *best_row = row;
                    *best_col = col;
                    *best_mask = possible;
                }
            }
            col++;
        }
        row++;
    }
    if (min_options == size + 1)
        return (0);
    return (1);
}

static int backtrack(int **tb, int order);


static int try_values(int **tb, int order, int row, int col,
    unsigned long long possible)
{
    int size;
    int val;

    size = board_size(order);
    val = 1;
    while (val <= size)
    {
        if (possible & (1ULL << (val - 1)))
        {
            tb[row][col] = val;
            if (backtrack(tb, order))
                return (1);
            tb[row][col] = 0;
        }
        val++;
    }
    return (0);
}

static int backtrack(int **tb, int order)
{
    int                 row;
    int                 col;
    int                 status;
    unsigned long long  possible;

    row = 0;
    col = 0;
    possible = 0;
    status = find_best_cell(tb, order, &row, &col, &possible);
    if (status == 0)
        return (1);
    if (status == -1)
        return (0);
    return (try_values(tb, order, row, col, possible));
}

void    solve(int **tb, int order)
{
    if (board_size(order) >= 64)
    {
        printf("Order too large to solve\n");
        return ;
    }
    if (!backtrack(tb, order))
        printf("No solution found\n");
}
