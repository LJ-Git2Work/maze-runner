/**
*Author: Lloyd Jones
*Purpose: Solves mazes
*
*Date: 22/04/2025
*Copyright @ 2025
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "maze_runner.h"
#include "All_Functions.h"
#define MAZE_SIZE 25

/********************	MAZE	********************/
void make_maze_file(){
	FILE *make_Maze;
	make_Maze = fopen("maze.txt", "w");
	
	for(int row = 0; row < MAZE_SIZE; row++){
		fputs("#########################\n",make_Maze);
	}
	fclose(make_Maze);
}

void make_2d_char_array_of_maze(char (*char_maze)[MAZE_SIZE]){
	FILE *File_char_maze;
	File_char_maze = fopen("maze.txt", "r");
	
	for(int row = 0; row < MAZE_SIZE; row++){
		for(int col = 0; col < MAZE_SIZE; col++){
			char_maze[row][col] = fgetc(File_char_maze);
		}
	}
}

void make_2d_block_array_of_2d_char_array(const char (*char_maze)[MAZE_SIZE], block (*block_maze)[MAZE_SIZE]){
	
	for(int row = 0; row < MAZE_SIZE; row++){
		for(int col = 0; col < MAZE_SIZE; col++){
			block_maze[row][col] = block_type(char_maze[row][col]);
			printf("%c", char_maze[row][col]);
		}
	}

}

void make_block_maze_file(block (*block_maze)[MAZE_SIZE]){
	FILE *File_block_Maze;
	File_block_Maze = fopen("block_Maze.txt","w");
	
	for(int row = 0; row < MAZE_SIZE; row++){
		for(int col = 0; col < MAZE_SIZE; col++){
			fprintf(File_block_Maze,"%d" , block_maze[row][col]);
		}
		fputc('\n', File_block_Maze);
	}
}

block block_type(char thing){
	switch (thing){
		case '*':
			return path;
		case '$':
			return m_exit;
		case '>':
			return start;
		default:
			return wall;
	}
}

/********************	MENU	********************/

int menu(){
	int choice;
	char *prompt = "Take Control [1] or Auto Run? [0]\n>> ";
	choice = get_int_in_range(prompt, 0, 1);
	return choice; 
}


/********************	RUNNER	********************/

void player_runner(){
	printf("PLAYER CHOSEN");
}


/********************	AUTO	********************/

void auto_runner(){
	printf("CHEATING BITCH CHOSEN!!!");
}


























