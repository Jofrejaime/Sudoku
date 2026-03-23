#include "sudoku.h"

//logica de backtracking aqui
#include "../sudoku.h"


// Propagação de restrições:
// Para cada célula vazia, calcula quais valores são possíveis
// verificando linha, coluna e quadrante (box) correspondente.
// Retorna um bitmask onde o bit i ligado significa que o valor (i+1) é possível.

static int  get_possible(int **tb, int order, int row, int col)
{
    int size = order * order;
    int used = 0;
    int i;

    // verificar linha 
    i = 0;
    while (i < size)
    {
        if (tb[row][i] != 0)
            used |= (1 << (tb[row][i] - 1));
        i++;
    }
    // verificar coluna 
    i = 0;
    while (i < size)
    {
        if (tb[i][col] != 0)
            used |= (1 << (tb[i][col] - 1));
        i++;
    }
    // verificar quadrante (box) 
    int box_row = (row / order) * order;
    int box_col = (col / order) * order;
    int r = box_row;
    while (r < box_row + order)
    {
        int c = box_col;
        while (c < box_col + order)
        {
            if (tb[r][c] != 0)
                used |= (1 << (tb[r][c] - 1));
            c++;
        }
        r++;
    }
    // inverte: bits ligados = valores possíveis
    return (~used) & ((1 << size) - 1);
}


// MRV (Minimum Remaining Values):
// Escolhe a célula vazia com menos valores possíveis.
// Reduz o espaço de busca significativamente.
// Retorna 1 se encontrou célula, 0 se não há células vazias (tabuleiro resolvido).

static int  find_best_cell(int **tb, int order, int *best_row, int *best_col)
{
    int size = order * order;
    int min_options = size + 1;
    int found = 0;
    int r = 0;

    while (r < size)
    {
        int c = 0;
        while (c < size)
        {
            if (tb[r][c] == 0)
            {
                int possible = get_possible(tb, order, r, c);
                int count = __builtin_popcount(possible);
                if (count == 0)
                    return (-1); // célula sem opções: caminho inválido 
                if (count < min_options)
                {
                    min_options = count;
                    *best_row = r;
                    *best_col = c;
                    found = 1;
                }
            }
            c++;
        }
        r++;
    }
    return (found);
}


// Backtracking com propagação de restrições:
// 1. Escolhe a melhor célula vazia (MRV)
// 2. Para cada valor possível nessa célula:
//    a. Coloca o valor
//    b. Chama recursivamente
//    c. Se falhar, remove o valor (backtrack)
// Retorna 1 se resolveu, 0 se não há solução.

static int  backtrack(int **tb, int order)
{
    int row = 0, col = 0;
    int result = find_best_cell(tb, order, &row, &col);

    if (result == 0)
        return (1);// sem células vazias: solução encontrada! 
    if (result == -1)
        return (0); // célula sem opções: caminho sem saída

    int possible = get_possible(tb, order, row, col);
    int size = order * order;
    int val = 1;

    while (val <= size)
    {
        if (possible & (1 << (val - 1)))
        {
            tb[row][col] = val;
            if (backtrack(tb, order))
                return (1);
            tb[row][col] = 0; // backtrack 
        }
        val++;
    }
    return (0);
}


// Função principal chamada pelo main.
// Tenta resolver o tabuleiro e imprime o resultado.

void    solve(int **tb, int order)
{
    if (!backtrack(tb, order))
        printf("Nenhuma solução\n");
}
