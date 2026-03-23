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

t_sudoku    *validate(char **argv, int argc)
{
    int i = 0, j = 0, k = 0;
    int size, order;

    if (argc < 2)
        return (NULL);
    char *line;
    
    int fd = open(argv[1],O_RDONLY);
    if (fd < 0)
        return(NULL);
    line = get_next_line(fd);
    order = atoi(line);
    if (order == 0)
        return (NULL);
    size = order * order;
    int **tab = malloc((size) * sizeof(int *));
    while(k < size)
    {
        tab[k] = malloc(size * sizeof(int));
        k++;
    }
    line = get_next_line(fd);
    while(line)
    {
        k = 0;
        i = 0;
        while(line[i] && line[i] != '\n')
        {
            if ((line[i] < '0' || line[i] > (size + '0')) && line[i] != ' ')
                return (NULL);
            if (line[i] >= '0' && line[i] <= (size + '0'))
            {
                if (k >= size)
                    return (NULL);
                tab[j][k++] = line[i] - '0';
            }
            i++;
        }
         if (k != size)
            return (NULL);
        j++;
        line = get_next_line(fd);
    }
    if (j != size)
        return (NULL);
    t_sudoku *sudoku = malloc(sizeof(t_sudoku));
    sudoku->tab = tab;
    sudoku->order = order;
    return (sudoku);
}
