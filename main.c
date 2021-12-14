#include "sudoku.h"

sudoku_tile grid[NBR_CASES];

int main (int argc, char* argv[])
{
  grid_init();
  req_start_grid();

  int i;
  for (i=1; i<=9; i++)
    clean_line(i);
  
  disp_final();
  disp_possible();
  
  return 0;
}
