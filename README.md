# Sudoku

Projeto Sudoku em C.

## Estrutura

- A raiz do repositório contém este README.
- O código-fonte está em `sudoku/`.

## Como compilar

No terminal, a partir da raiz:

```sh
cd sudoku
mingw32-make
```

Se tiveres `make` disponível no teu ambiente:

```sh
cd sudoku
make
```

## Como executar

Dentro de `sudoku/`:

```sh
./sudoku map1.txt
./sudoku map2.txt
```

## Arquitetura

O projeto está organizado em módulos pequenos:

- `main.c`: ponto de entrada, carrega o mapa, resolve e imprime.
- `validator/parser.c`: parsing da ordem e das linhas do tabuleiro.
- `validator/loader.c`: leitura do ficheiro, validação de formato e construção de `t_sudoku`.
- `backtracking/backtracking.c`: solver com backtracking + heurística MRV.
- `general_utils/get_next_line.c`: leitura linha a linha do ficheiro.
- `general_utils/utils.c`: utilitários gerais (`print`, `free_sudoku`).

Fluxo resumido:

1. `main` chama `load_sudoku(path)`.
2. `loader` usa o `parser` para validar e preencher a grelha.
3. `main` chama `solve(tab, order)`.
4. O solver tenta encontrar solução por backtracking.
5. O resultado final é impresso e a memória é libertada.
