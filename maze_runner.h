/**
*Author: Lloyd Jones
*Purpose: Solves mazes
**/

#ifndef MAZE
#define MAZE

block block_type(char thing);
void make_maze_file();
void make_2d_char_array_of_maze(char (*char_maze)[MAZE_SIZE]);
void make_2d_block_array_of_2d_char_array(const char (*char_maze)[MAZE_SIZE], block (*block_maze)[MAZE_SIZE]);
void make_block_maze_file(block (*block_maze)[MAZE_SIZE]);
int menu();
block get_block(block (*block_maze)[MAZE_SIZE], direction facing, int y_pos, int x_pos);
void move_direction(direction facing, int *x_pos, int *y_pos);
void display_graphics(block front, block left, block right);
void display_art(char *tag);
void player_runner(block (*block_maze)[MAZE_SIZE]);
void get_start_coord(block (*block_maze)[MAZE_SIZE], int *y, int *x);
void display_view(block (*block_maze)[MAZE_SIZE], direction facing, int y_pos, int x_pos);
char get_block_graphic(block item);
char get_user_facing_graphic(direction facing);
#endif