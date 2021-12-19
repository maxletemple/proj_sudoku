#include "sudoku.h"

/******
Cette version ne résout que les grilles ayant une solution et dont on peut supposer des valeurs, sinon on rentre dans une boucle infinie
******/

sudoku_tile grid[NBR_CASES];
Affectation history[NBR_CASES];
int history_index = 0;

int main (int argc, char* argv[])
{
  grid_init();
  req_start_grid();
  Sudoku_ensemble m_ensemble = creation_ensemble();

  while (!is_grid_full())
  {
    while (valid_exist(&m_ensemble))
      ;

    while (guess_value() && is_grid_valid())
    {
      while (valid_exist(&m_ensemble))
        ;
    }

    if (!is_grid_full())
      back_play(&m_ensemble);
  }

  printf("final\n");
  disp_final();

  return 0;
}