#include "sudoku.h"

sudoku_tile grid[NBR_CASES];
Affectation history[NBR_CASES];
int history_index = 0;

int main (int argc, char* argv[])
{
  grid_init();
  req_start_grid();
  Sudoku_ensemble m_ensemble = creation_ensemble();
  disp_final();

  int grille_sudoku = RESOLVABLE;
  while (!is_grid_full() && grille_sudoku == RESOLVABLE)
  {
    while (valid_exist(&m_ensemble))
      ;

    while (is_grid_valid() && guess_value())
    {
      while (valid_exist(&m_ensemble))
        ;
    }

    if (!is_grid_full())
      grille_sudoku = back_play(&m_ensemble);
  }

  if (grille_sudoku == RESOLVABLE)
  {
    printf("\nGrille resolue\n");
    disp_final();
    printf("\n");
  }
  else
    printf("\nGrille irresolvable\n\n");

  

  return 0;
}