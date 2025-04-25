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
		case ' ':
			return path;
		case 'E':
			return m_exit;
		case 'S':
			return start;
		default:
			return wall;
	}
}

/********************	MENU	********************/

int menu(){
	int choice;

	printf(
" __  __                 ____                              _ _ _ \n"
"|  \\/  | __ _ _______  |  _ \\ _   _ _ __  _ __   ___ _ __| | | |\n"
"| |\\/| |/ _` |_  / _ \\ | |_) | | | | '_ \\| '_ \\ / _ \\ '__| | | |\n"
"| |  | | (_| |/ /  __/ |  _ <| |_| | | | | | | |  __/ |  |_|_|_|\n"
"|_|  |_|\\__,_/___\\___| |_| \\_\\\\__,_|_| |_|_| |_|\\___|_|  (_|_|_)\n");
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

/*
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
*/

void display_view(block (*block_maze)[MAZE_SIZE], direction facing, int y_pos, int x_pos){
	char grid[GRID_SIZE][GRID_SIZE];
	int grid_start_relative = 0 - GRID_SIZE / 2; 		//If gridsize is 5, div 2 is 2, grid left corner = 0 - 2, which is -2. THis is where the display grid starts relative to the user, grid must be odd num 
	//printf("gridstartrelative = %d\n", grid_start_relative);
	//printf("xpos = %d, ypos = %d\n", x_pos, y_pos);
	for(int i = 0, ii = grid_start_relative; i < GRID_SIZE; i++, ii++){
		for(int j = 0, jj = grid_start_relative; j < GRID_SIZE; j++, jj++){
			int map_y = y_pos + ii;
			int map_x = x_pos + jj;
			if(map_x >= MAZE_SIZE || map_x < 0 || map_y >= MAZE_SIZE || map_y < 0){
				grid[i][j] = 'X';
				//printf("jj = %d, ii = %d\n", jj, ii);
			}else if(ii == 0 && jj == 0){
				grid[i][j] =  get_user_facing_graphic(facing);
			}else{
				grid[i][j] = get_block_graphic(block_maze[map_y][map_x]);
			}
		}
	}

	for(int i = 0; i < GRID_SIZE; i++){
		for(int j = 0; j < GRID_SIZE; j++){
			if(i == 0 || j == 0 || i == GRID_SIZE - 1 || j == GRID_SIZE - 1 ){
				if(grid[i][j] == 'X'){
					printf("%c ", grid[i][j]);
				}else{
					printf(". ");
				}
			}else{
				printf("%c ", grid[i][j]);
			}
		}
		printf("\n");
	}
}

char get_block_graphic(block item){
	switch(item){
		case wall:
			return '#';
		case path:
			return ' ';
		case start:
			return 'S';
		case m_exit:
			return '$';
	}
}

char get_user_facing_graphic(direction facing){
	switch(facing){
		case North:
			return '^';
		case South:
			return 'v';
		case East:
			return '>';
		case West:
			return '<';
	}
}
















