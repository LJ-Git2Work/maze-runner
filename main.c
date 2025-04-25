/**
*Author: Lloyd Jones
*Purpose: Solves mazes
**/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "maze_runner.h"
#include "runner.h"
#include "All_Functions.h"

int main(){
	
	block block_maze[MAZE_SIZE][MAZE_SIZE];	
	char char_maze[MAZE_SIZE][MAZE_SIZE];
	make_2d_char_array_of_maze(char_maze); 							//Assigns all char of maze file to 2d array
	make_2d_block_array_of_2d_char_array(char_maze, block_maze);  	//Copies the char of that 2d array to type block in another 2d array
	make_block_maze_file(block_maze);
	
	if(menu()){
		system("cls");
		player_runner(block_maze);
	}else
		//auto_runner();
	return 0;
}


