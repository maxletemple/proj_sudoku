#include "sudoku.h"

void grid_init (void)
{
  int i;
  int j;

  for (i=0; i<NBR_CASES; i++)
    {
      grid[i].value = 0;
      for (j=0; j<9; j++)
	grid[i].possible[j] = 1;
    }
}

void disp_final (void)
{
  int l;
  int c;

  printf("\n");
  for (l=0; l<9; l++)
    {
      for (c=0; c<9; c++)
	{
	  if ( grid[ l*9 + c ].value == 0 )
	    printf("  ");
	  else
	    printf("%d ", grid[ l*9 + c ].value);
	}
      printf("|\n");
    }
}

void disp_possible (void)
{
  int d;
  int l;
  int c;

  for (d=1; d<=9; d++)
    {
      printf("\n");
      printf("d= %d\n",d);
      for (l=0; l<9; l++)
	{
	  for (c=0; c<9; c++)
	    {
	      if ( grid[ l*9 + c ].value == INCONNU )
          if ( grid[ l*9 + c ].possible[d-1] == POSSIBLE )
            printf("+ ");
          else
            printf("  ");
        else
          if ( grid[ l*9 + c ].value == d )
              printf("%d ", grid[ l*9 + c ].value);
          else 
            printf(". ");
        }
      printf("|\n");
	}
    }
}

void set_tile_value (sudoku_tile *tile, char value)
{
  tile->value = value;
}

void req_start_grid (void)
{
  int l;
  int c;
  char val;
  
  for (l=0; l<9; l++)
  {
    for (c=0; c<9; c++)
    {
      scanf("%c ", &val);

      if ( val >= '1' && val <= '9')
      { 
        set_tile_value ( &grid[ l*9 + c ], val-'0' );
      }
      else
      {
        set_tile_value ( &grid[ l*9 + c ], 0);
      }
    }
  }
}

int clean_line (int n_line)
{
  n_line--;
  int c;
  int i;
  int ret=0;
  char val;

  for (c=0; c<9; c++)
  {
    val = grid[ n_line*9 + c ].value;
    if ( val != INCONNU )
    {
      for (i=0; i<9; i++)
      {
        if ( grid[ n_line*9 + i ].possible[val-1] == POSSIBLE )
        {
          grid[ n_line*9 + i ].possible[val-1] = IMPOSSIBLE;
          ret = 1;
        }
      }
    }
  }

  return ret;
}

