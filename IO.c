/**
*Author: Lloyd Jones
*Purpose: Is the games menu and graphics display
**/

#include <stdio.h>
#include <stdlib.h>
#include "all.h"

/********************	MENU	********************/

int menu(){
	int choice = 0;

	printf(	" __  __                 ____                              _ _ _ \n"
			"|  \\/  | __ _ _______  |  _ \\ _   _ _ __  _ __   ___ _ __| | | |\n"
			"| |\\/| |/ _` |_  / _ \\ | |_) | | | | '_ \\| '_ \\ / _ \\ '__| | | |\n"
			"| |  | | (_| |/ /  __/ |  _ <| |_| | | | | | | |  __/ |  |_|_|_|\n"
			"|_|  |_|\\__,_/___\\___| |_| \\_\\\\__,_|_| |_|_| |_|\\___|_|  (_|_|_)\n"
			);
			
	const char* prompt = "\nTake Control [1] or Auto Run? [0]\n" MENU_CURSOR;		
	const char* type_error = "\n\t\t\t\t\t#ERROR: invalid input type!\r" MENU_CURSOR;
	const char* range_error = "\n\t\t\t\t\t#ERROR: input is NOT inside the valid range!\r" MENU_CURSOR;
	
	choice = get_int_in_range("%d", 0, 1, prompt, type_error, range_error);
	return choice; 
}

void get_user_input(char* input){
    printf(MAZE_CURSOR);
	fgets(input, LINE_SIZE, stdin);
	input[strcspn(input, "\n")] = '\0';
	//printf("%s-- %s-- #\n#", input, input);
}

void display_input_error(const char* input){
	printf("<%s> is not a valid command!", input);
	printf("\nValid Commands are: move/turn, left, right or back\n");
}

/********************	GRAPHICS	********************/
void display_maze(const Grid* maze, Player* user){
	Grid map_view = {0};	
	grid_init(&map_view, VIEW_SIZE, VIEW_SIZE, sizeof(char));
	system("cls");
	create_map_view(maze, user, &map_view);
	display_map_view(&map_view);
	free(map_view.data);
}

void create_map_view(const Grid* maze, const Player* user, Grid* map_view){
	int offset = 0 - VIEW_SIZE / 2;	/* This is where the display grid starts relative to the user, grid must be odd num If grid_size is 5, div 2 is 2, grid left corner = 0 - 2, which is -2. view goes from -2 to +2 relative to the user*/
	//TRACE("Create Map view start");
	const char block_chars[] = {
		[WALL] = '#', 
		[PATH] = ' ',
		[START] = 'S',
		[M_EXIT] = '$'
	};

	const char user_graphic[] = {
		[NORTH] = '^',
		[EAST] = '>',
		[SOUTH] = 'v',
		[WEST] = '<'
	};

	for(int y = 0, dy = offset; y < VIEW_SIZE; y++, dy++)
	{
		for(int x = 0, dx = offset; x < VIEW_SIZE; x++, dx++)
		{
			int maze_y = user->y_pos + dy;
			int maze_x = user->x_pos + dx;
			
			if(maze_x > maze->cols || maze_x < 0 || maze_y > maze->rows || maze_y < 0)
			{
				GRID_SET(char, map_view->data, y, x, map_view->cols, 'X');
			}
			else if(dy == 0 && dx == 0)
			{
				GRID_SET(char, map_view->data, y, x, map_view->cols, user_graphic[user->facing]);
			}
			else
			{
				BlockType square = GRID_GET(BlockType, maze->data, maze_y, maze_x, maze->cols);
				GRID_SET(char, map_view->data, y, x, map_view->cols, block_chars[square]);
			}
		}
	}
	//TRACE("Create Map view end");
}


void display_map_view(Grid* map_view){
	//TRACE("Display map view start");
	char c;
	for(int row = 0; row < map_view->rows; row++)
	{
		for(int col = 0; col < map_view->cols; col++)
		{
			if(GRID_GET(char, map_view->data, row, col, map_view->cols) == 'X')
			{
				printf("  ");
			}
			else if(row == 0 || col == 0 || row == VIEW_SIZE - 1 || col == VIEW_SIZE - 1)
			{
				printf("~ ");
			}
			else
			{
				c = GRID_GET(char, map_view->data, row, col, map_view->cols);
				printf("%c ", c);
			}
		}
		printf("\n");
	}
	//TRACE("Display map view end");
}
/*
char get_block_graphic(BlockType item){
	switch(item){
		case WALL: 		return '#';
		case PATH: 		return ' ';
		case START: 	return 'S';
		case M_EXIT: 	return '$';
		default: 		return '?';
	}
}

char get_user_graphic(CardinalDir facing){
	
	
	switch(facing){
		case NORTH: return '^';
		case SOUTH: return 'v';
		case EAST:  return '>';
		case WEST:  return '<';
		default: 	return '?';
	}
}


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
