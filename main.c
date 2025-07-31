/**
*Author: Lloyd Jones
*Purpose: Solves mazes
**/

#include <stdio.h>
#include <stdlib.h>
#include "all.h"

int main(){
	const char* maze_filename = "maze.txt";
	Player user = {0};
	/*
	if(open_file(maze_filename)){
		printf("\nERROR: File \"%s\" could not be opened\n", maze_filename);
		return -1;
	}*/
	Grid* maze = create_maze_from_file(maze_filename);
	
	if(menu())
		user.identity = HUMAN;
	else
		user.identity = BOT;
	
	run_game(maze, &user);
		
	return 0;
}


