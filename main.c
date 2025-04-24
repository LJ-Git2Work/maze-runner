/**
*Author: Lloyd Jones
*Purpose: Solves mazes
*
*Date: 21/04/2025
*Copyright @ 2025
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "maze_runner.h"
#include "All_Functions.h"
#define MAZE_SIZE 25

int main(){
	
	block block_maze[MAZE_SIZE][MAZE_SIZE];	
	char char_maze[MAZE_SIZE][MAZE_SIZE];
	make_maze_file(); 												//Creates a blank maze file 
	make_2d_char_array_of_maze(char_maze); 							//Assigns all char of maze file to 2d array
	make_2d_block_array_of_2d_char_array(char_maze, block_maze);  	//Copies the char of that 2d array to type block in another 2d array
	make_block_maze_file(block_maze);
	
	if(menu())
		player_runner();
	else
		auto_runner();
	return 0;
}


