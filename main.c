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

  disp_final();

  while ( valid_exist(&m_ensemble) );

  disp_final();

  return 0;
}
