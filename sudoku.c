#include "sudoku.h"

/**
 * @brief Initialise la grille. Pour chaque case toutes les valeurs sont possibles et sa valeur vaut 0
 */
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

/**
 * @brief Affiche la grille
 */
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

/**
 * @brief Affiche 9 grilles. La ième grille affiche les possibilités de placement pour le nombre i.
 */
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

// comment
void set_tile_value (sudoku_tile *tile, char value)
{
  tile->value = value;
}

/**
 * @brief Demande une grille en entrée et initialise la grille
 */
void req_start_grid(void)
{
  int l;
  int c;
  char val;

  for (l = 0; l < 9; l++)
  {
    for (c = 0; c < 9; c++)
    {
      scanf("%c ", &val);

      if (val >= '1' && val <= '9')
      {
        set_tile_value(&grid[l * 9 + c], val - '0');
      }
      else
      {
        set_tile_value(&grid[l * 9 + c], 0);
      }
    }
  }
}

/**
 * @brief enlève les valeurs impossibles d'une ligne
 * @param n_line : numéro de la ligne
 * @return 1 si au moins une valeur impossible a été ajouté sur une case, sinon 0
 */
int clean_line(int n_line)
{
  n_line--;
  int c;
  int i;
  int ret = 0;
  char val;

  for (c = 0; c < 9; c++)
  {
    val = grid[n_line * 9 + c].value;
    if (val != INCONNU)
    {
      for (i = 0; i < 9; i++)
      {
        if (grid[n_line * 9 + i].possible[val - 1] == POSSIBLE)
        {
          grid[n_line * 9 + i].possible[val - 1] = IMPOSSIBLE;
          ret = 1;
        }
      }
    }
  }

  return ret;
}

/**
 * @brief Pour chaque case de grid, vérifie si une seule valeur est marquée comme possible. Si c'est le cas, la fonction écrit cette valeur dans la case comme connue
 * @param Grille de sudoku (tableau de sudoku_tile)
 * @return 0 si aucune case n'a été modifiée, 1 si au moins une case a été modifiée
 */
int validate_single_possibility (sudoku_tile *grid)
{
  int i;
  int j;
  int compteur;
  int ret = 0;

  for (i=0; i<NBR_CASES; i++)
  {
    compteur = 0;
    for (j=0; j<9; j++)
    {
      if (grid[i].possible[j])
        compteur++;
    }

    if (compteur == 1 && grid[i].value == INCONNU )
    {
      for (j = 0; j < 9; j++)
      {
        if (grid[i].possible[j])
        {
          grid[i].value = j + 1;
          grid[i].possible[j] = IMPOSSIBLE;
          ret = 1;
          break;
        }
      }
    }

  }

  return ret;
}

/**
 * @brief Pour chaque valeur v (entre 1 et 9) si une seule case contient v comme valeur possible, on modifie la valeur de cette case
 * @param n_line : numéro de la ligne
 * @return 1 si au moins une case est modifiée, 0 sinon
 */
int valid_exist_in_line (int n_line)
{
  n_line--; 
  int i;
  int compteur;
  int v;
  int ret = 0;

  for (v=1; v<=9; v++)
  {
    compteur = 0;
    for (i=0; i<9; i++)
    {
      if (grid[ n_line*9 + i ].possible[v-1])
        compteur++;
    }

    if (compteur == 1)
    {
      for (i=0; i<9; i++)
      {
        if (grid[ n_line*9 + i ].possible[v-1])
        {
          grid[ n_line*9 + i ].value = v;
          grid[ n_line*9 + i ].possible[v-1] = IMPOSSIBLE;
          ret = 1;
        }
      }
    }

  }

  return ret;
}

/**
 * @brief Affiche un sous-ensemble
 * @param m_ensemble : sous-ensemble de type Subset
 */
void disp_subset (Subset m_ensemble)
{
  int i;
  for (i=0; i<9; i++)
    printf("%d ", m_ensemble[i]->value);
  printf("\n");
}
/**
 * @brief Renvoie un sous-ensemble correspondant à la ligne dont le numéro est l'argument reçu, SUBSET ALLOUE DYNAMIQUEMENT !!!
 * @param n_line : numéro de la ligne
 * @return sous-ensemble
 */
Subset get_line_subset (int n_line)
{
  n_line--;
  int i;
  Subset m_ensemble = NULL;

  m_ensemble = malloc( sizeof(void*) * 9 );
  if ( m_ensemble == NULL )
  {
    printf("Erreur malloc get_line_subset\n");
    exit(1);
  }

  for (i=0; i<9; i++)
  {
    m_ensemble[i] = &grid[ n_line*9 + i ];
  }

  return m_ensemble;
}

/**
 * @brief Renvoie un sous-ensemble correspondant à la colonne dont le numéro est l'argument reçu, SUBSET ALLOUE DYNAMIQUEMENT !!!
 * @param n_col : numéro de la colonne
 * @return sous-ensemble
 */
Subset get_col_subset (int n_col)
{
  n_col--;
  int i;
  Subset m_ensemble = NULL;

  m_ensemble = malloc( sizeof(void*) * 9 );
  if ( m_ensemble == NULL )
  {
    printf("Erreur malloc get_col_subset\n");
    exit(1);
  }

  for (i=0; i<9; i++)
  {
    m_ensemble[i] = &grid[ i*9 + n_col ];
  }

  return m_ensemble;
}

/**
 * @brief Renvoie sous_ensemble carré
 * @param n_carre : numéro du carré, en partant d'en haut à gauche et en allant dans le sens de lecture, SUBSET ALLOUE DYNAMIQUEMENT !!!
 * @return sous_ensemble
 */
Subset get_subsq_subset (int n_carre)
{
  n_carre--;
  int l;
  int c;
  Subset m_ensemble = NULL;

  m_ensemble = malloc( sizeof(void*) * 9 );
  if ( m_ensemble == NULL )
  {
    printf("Erreur malloc get_subsq_subset\n");
    exit(1);
  }

  if ( 3 <= n_carre && n_carre <= 5 )
    n_carre += 6;
  else if ( 6 <= n_carre && n_carre <= 8 )
    n_carre += 12;

  for (l=0; l<3; l++)
  {
    for (c=0; c<3; c++)
    {
      m_ensemble[ l*3 + c ] = &grid[ n_carre*3 + c + l*9 ];
    }
  }

  return m_ensemble;
}

/**
 * @brief Crée tous les sous-ensembles de la grille : lignes, colonnes et carrés
 * @return tous les sous-ensembles
 */
Sudoku_ensemble creation_ensemble (void)
{
  int i;
  Sudoku_ensemble m_ensembles;

  for (i=0; i<9; i++)
  {
    m_ensembles.line[i] = get_line_subset(i);
    m_ensembles.col[i] = get_col_subset(i);
    m_ensembles.carre[i] = get_subsq_subset(i);
  }

  return m_ensembles;
}