#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

#define NBR_CASES 81
#define INCONNU 0
#define POSSIBLE 1
#define IMPOSSIBLE 0
#define RESOLVABLE 1
#define IRRESOLVABLE 0

// représente une case de la grille
typedef struct
{
  char value;
  char possible[9];
} sudoku_tile;

typedef sudoku_tile** Subset;

// contient tous les sous-ensembles
typedef struct
{
  Subset line[9];
  Subset col[9];
  Subset carre[9];
} Sudoku_ensemble;

typedef struct
{
  sudoku_tile *tile;
  char supposed;
} Affectation;

extern sudoku_tile grid[NBR_CASES];
extern Affectation history[NBR_CASES];
extern int history_index;

void grid_init (void);
void disp_final (void);
void disp_possible (void);
void set_tile_value (sudoku_tile *tile, char value, char supposed);
void req_start_grid (void);
int clean_line (int n_line);
int validate_single_possibility (sudoku_tile *grid);
int valid_exist_in_line (int n_line);
void disp_subset (Subset m_ensemble);
Subset get_line_subset (int n_line);
Subset get_col_subset (int n_col);
Subset get_subsq_subset (int n_carre);
Sudoku_ensemble creation_ensemble (void);
int clean_subset(Subset m_subset);
int valid_exist_in_subset (Subset m_subset);
int clean_grid (Sudoku_ensemble *m_ensemble);
int valid_exist (Sudoku_ensemble *m_ensemble);
void afficher_history (void);
int is_grid_valid (void);
int guess_value (void);
void re_init (void);
int back_play (Sudoku_ensemble *m_ensemble);
int is_grid_full (void);

#endif
