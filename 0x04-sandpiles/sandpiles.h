#ifndef SANDPILES_H
#define SANDPILES_H

static void print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int is_unstable(int grid[3][3]);
void toppling_round(int grid[3][3]);

#endif