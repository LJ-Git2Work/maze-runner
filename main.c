/**
*Author: Lloyd Jones
*Purpose: Solves mazes
**/

#include <stdio.h>
#include <stdlib.h>
#include "all.h"

int main(){
	const char* maze_filename = "maze.txt";
	Grid maze = {0};
	
	/*
	if(open_file(maze_filename)){
		printf("\nERROR: File \"%s\" could not be opened\n", maze_filename);
		return -1;
	}*/
	
	create_maze_from_file(maze_filename, &maze);
	
	TRACE("Start");
	if(menu()){
		//system("cls");
		player_runner(&maze);
	}else
		//auto_runner();
	return 0;

}


