/**
*Author: Lloyd Jones
*Purpose: Makes the 2d Maze
**/

#include <stdio.h>
#include <stdlib.h>
#include "all.h"

/********************	MAZE	********************/
Grid* getMaze() {
	static Grid Maze;
	static int initialised = 0;
	
	if(!initialised){
		Maze.data = NULL;
		Maze.rows = 0;
		Maze.cols = 0;
		Maze.elem_size = 0;
		initialised = 1;
	}
	return &Maze;
}
/*
Grid* getDisplay() {
	static Grid MapView;
	static initialised = 0;
	
	if(!initialised){
		MapView.data = NULL;
		MapView.rows = 0;
		MapView.cols = 0;
		MapView.elem_size = 0;
		initialised = 1;
	}
	return &Maze;
}

*/
Grid* create_maze_from_file(const char *filename){
	char c;
	int rows, cols;
	FILE *mazeFile;
	
	mazeFile = fopen(filename, "r");
	if(mazeFile == NULL){
		//TRACE("Maze FILE pointer is NULL");
		exit(1);
	}

	rows = count_file_lines(mazeFile);
	//VARTRACE(rows, "%d");
	cols = longest_line_size(mazeFile);
	//VARTRACE(cols, "%d");
	
	//grid_init(maze, rows, cols, sizeof(BlockType));
	
	Grid* maze = getMaze();
	if(maze == NULL){
		//TRACE("Maze data pointer is NULL");
		exit(EXIT_FAILURE);
	} else {
		maze->rows = rows;
		maze->cols = cols;
		maze->elem_size = sizeof(BlockType);
		maze->data = malloc(rows * cols * maze->elem_size);
		if(maze->data == NULL){
			TRACE("Maze data pointer is NULL");
			exit(EXIT_FAILURE);
		}
	}
	
	fseek(mazeFile, 0, SEEK_SET);
	
	//TRACE("Start make maze");
	for(int row = 0; row < maze->rows; row++)
	{
		for(int col = 0; col <= maze->cols; col++)
		{	
			c = fgetc(mazeFile);
			if(c != EOF && c != '\n'){
					GRID_SET(BlockType, maze->data, row, col, maze->cols, get_block_type(c));
			}else{	
				while(col < maze->cols - 1){
					GRID_SET(BlockType, maze->data, row, col, maze->cols, WALL);
					col++;
				}
				break;
			}
			
		}
	}
	fclose(mazeFile);
	return maze;
	//TRACE("Maze Created");
}

BlockType get_block_type(char c){
	switch (c){
		case ' ': return PATH;
		case 'E': return M_EXIT;
		case 'S': return START;
		default:  return WALL;
	}
}