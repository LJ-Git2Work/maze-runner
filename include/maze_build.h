/**
*Author: Lloyd Jones
*Purpose: Solves mazes
**/

#ifndef MAZE_BUILD
#define MAZE_BUILD
void create_maze_from_file(const char *filename, Grid *maze);
BlockType get_block_type(char c);
#endif