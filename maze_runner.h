/**
*Author: Lloyd Jones
*Purpose: Solves mazes
*
*Date: 22/04/2025
*Copyright @ 2025
*
*/

#ifndef MAZE
#define MAZE
#define MAZE_SIZE 25

typedef enum
	{wall, path, start, m_exit}
block;

block block_type(char thing);
void make_maze_file();
void make_2d_char_array_of_maze(char (*char_maze)[MAZE_SIZE]);
void make_2d_block_array_of_2d_char_array(const char (*char_maze)[MAZE_SIZE], block (*block_maze)[MAZE_SIZE]);
void make_block_maze_file(block (*block_maze)[MAZE_SIZE]);
int menu();
void player_runner();
void auto_runner();
#endif