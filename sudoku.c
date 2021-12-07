#include"stdio.h"

struct sudoku_tile{
    char value;
    char possible[9];
};

struct sudoku_tile grid[81];

void initialisation(){
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            grid[(i-1) * 9 + j - 1].value = '0';
            for (int p = 0; p < 9; ++p) {
                grid[(i-1) * 9 + j - 1].possible[p] = p + 1;
            }
        }
    }
}

void disp_final(){
    for (int i = 1; i <= 9 ; ++i) {
        for (int j = 1; j <= 9; ++j) {
            printf("%c ", grid[(i-1) * 9 + j - 1].value);
        }
        printf("\n");
    }
}

void disp_possible(){
    for(int n = 1; n <= 9; n++ ) {
        for (int i = 1; i <= 9; ++i) {
            for (int j = 1; j <= 9; j++) {
                struct sudoku_tile tile = grid[(i - 1) * 9 + j - 1];
                char c;
                if (tile.value == '0') {
                    if (tile.possible[n - 1] != '0') c = '+';
                    else c = ' ';
                } else{
                    if (tile.value == tile.possible[n - 1]) c = tile.value;
                    else c = '.';
                }
            }
        }
    }
}

void set_tile_value(struct sudoku_tile *tile, char val){
    struct sudoku_tile t = *tile;
    t.value = val;
    *tile = t;
}

int main(int argc, char **argv){
    initialisation();
    set_tile_value(&grid[9], '1');
    disp_final();
}