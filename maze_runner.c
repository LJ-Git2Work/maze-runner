/**
*Author: Lloyd Jones
*Purpose: 
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "maze_runner.h"
#include "All_Functions.h"


/********************	MAZE	********************/


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
			//printf("%c", char_maze[row][col]);
		}
	}

}

void make_block_maze_file(block (*block_maze)[MAZE_SIZE]){
	FILE *File_block_Maze;
	File_block_Maze = fopen("block_Maze.txt","w");
	
	for(int row = 0; row < MAZE_SIZE; row++){
		for(int col = 0; col < MAZE_SIZE; col++){
			fprintf(File_block_Maze,"%d" , block_maze[row][col]);
			//printf("%d" , block_maze[row][col]);
		}
		//printf("\n");
		fputc('\n', File_block_Maze);
	}
	fclose(File_block_Maze);
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


/********************	POSITIONING	********************/

void get_start_coord(block (*block_maze)[MAZE_SIZE], int *y, int *x){
	for(int i = 0; i < MAZE_SIZE; i++){
		for(int j = 0; j < MAZE_SIZE; j++){
			if(block_maze[i][j] == start){
				*y = i;
				*x = j;
			}
		}
	}
}

block get_block(block (*block_maze)[MAZE_SIZE], direction facing, int y_pos, int x_pos){
    
    switch(facing){
        case North:
			return block_maze[y_pos-1][x_pos];
		case South:
            return block_maze[y_pos+1][x_pos];
		case West:
            return block_maze[y_pos][x_pos-1];
		case East:
            return block_maze[y_pos][x_pos+1];
    }
}

void move_direction(direction facing, int *x_pos, int *y_pos){
    switch(facing){
        case North:
			//printf("Move North\n");
            *y_pos = *y_pos - 1;
			break;
        case South:
			//printf("Move South\n");
			*y_pos = *y_pos + 1;
			break;
        case West:
			//printf("Move West\n");
            *x_pos = *x_pos - 1;
			break;
        case East:
			//printf("Move East\n");
            *x_pos = *x_pos + 1;
			break;
    }
}


/********************	GRAPHICS	********************/


void display_graphics(block front, block left, block right){
	char *tag;
	tag = (char*) malloc (20 * sizeof(char));

    if(front == wall && left == wall && right == wall){
        tag = "___all_walls___";
		//printf("WWW\n");
    }else if(front == path && left == path && right == path){
        tag = "___all_paths___";
		//printf("PPP\n");
    }else if(front == path && left == wall && right == wall){
        tag = "___forward_path___";
		//printf("WFW\n");
    }else if(front == wall && left == path && right == path){
        tag = "___left_right_paths___";
		//printf("LWR\n");
    }else if(front == wall && left == path && right == wall){
        tag = "___left_path___";
		//printf("LWW\n");
    }else if(front == wall && left == wall && right == path){
        tag = "___right_path___";
		//printf("WWR\n");
    }else if(front == start){
        tag = "___start_sign___";
		//printf("START\n");
    }else if(front == m_exit){
        tag = "___exit_sign___";
		//printf("EXIT\n");
	}

	display_art(tag);
	
	free(tag);
}


void display_art(char *tag) {
    FILE *artfile = fopen("ascii_art.txt", "r");

    char line[200];
    int found = 0;

    while (!found && fgets(line, sizeof(line), artfile)) {
        if (strncmp(line, tag, strlen(tag)) == 0)
            found = 1;
    }

    if (found) {
        while (fgets(line, sizeof(line), artfile)) {
            if (strncmp(line, "___", 3) == 0)
                break;
            printf("%s", line);
        }
    }

    fclose(artfile);
}






















