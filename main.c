#include "sudoku.h"

/******
A faire si possible
- fonction pour free les variables allouées dynamiquement

******/

sudoku_tile grid[NBR_CASES];

int main (int argc, char* argv[])
{
  grid_init();
  req_start_grid();
  Sudoku_ensemble m_ensemble = creation_ensemble();

  printf("\n\n");
  disp_final();

  int n_line = 6;
  int n_col = 8;
  int n_carre = 5;
  printf("ligne %d\n", n_line);
  disp_subset(m_ensemble.line[n_line]);
  printf("colonne %d\n", n_col);
  disp_subset(m_ensemble.col[n_col]);
  printf("carre %d\n", n_carre);
  disp_subset(m_ensemble.carre[n_carre]);

  return 0;
}
