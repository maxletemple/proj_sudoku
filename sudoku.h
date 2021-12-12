#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

#define NBR_CASES 81
#define INCONNU 0
#define POSSIBLE 1
#define IMPOSSIBLE 0

typedef struct
{
  char value;
  char possible[9];
} sudoku_tile;

extern sudoku_tile grid[NBR_CASES];

void grid_init (void);
void disp_final (void);
void disp_possible (void);
void set_tile_value (sudoku_tile *tile, char value);
void req_start_grid (void);
int clean_line (int n_line);

#endif
