#include "sudoku.h"

/******
Cette version teste toutes les possibilités normalement, pas testé mis à part sur grille du sujet car difficile de construire les grilles permettant de vérifier cela
******/

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

    while (guess_value() && is_grid_valid())
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