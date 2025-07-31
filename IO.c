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
	printf("\"%s\" is not a valid command!", input);
	printf("\nValid Commands are: move/turn, left, right or back\n");
}

/********************	GRAPHICS	********************/
void create_and_display_maze(const Grid* maze, const Player* user, void (*map_display)(Grid*, const Player*)){
	Grid map = {0};	
	map.rows = maze->rows;
	map.cols = maze->cols;

	grid_init(&map, map.rows, map.cols, sizeof(char));
	create_map(maze, &map);
	
	map_display(&map, user);
	/*
	if(user->identity != HUMAN){
		display_player_map(&map, user);
	}else if(user->identity != BOT){
		display_map_all(&map, user);
	}
	*/
	free(map.data);
}

void create_map(const Grid* maze, Grid* map){
	const char tile_chars[] = {
		[WALL] = '#', 
		[PATH] = ' ',
		[START] = 'S',
		[M_EXIT] = '$'
	};

	for(int row = 0; row < maze->rows; row++)
	{
		int col;
		for(col = 0; col < maze->cols; col++)
		{
			BlockType tile = GRID_GET(BlockType, maze->data, row, col, maze->cols);
			GRID_SET(char, map->data, row, col, map->cols, tile_chars[tile]);
		}
	}
}

void display_player_map(Grid* map, const Player* user){
	int offset = 0 - VIEW_SIZE / 2;	/* This is where the display grid starts relative to the user, grid must be odd num If grid_size is 5, div 2 is 2, grid left corner = 0 - 2, which is -2. view goes from -2 to +2 relative to the user*/
	const char user_graphic[] = {
		[NORTH] = '^',
		[EAST] = '>',
		[SOUTH] = 'v',
		[WEST] = '<'
	};
	
	for(int row = 0, dy = offset; row < VIEW_SIZE; row++, dy++)
	{
		for(int col = 0, dx = offset; col < VIEW_SIZE; col++, dx++)
		{
			int tile_row = user->y_pos + dy;
			int tile_col = user->x_pos + dx;
			
			if(tile_col > map->cols || tile_col < 0 || tile_row > map->rows || tile_row < 0)
			{
				printf("X ");
			}
			else if(row == 0 || col == 0 || row == VIEW_SIZE - 1 || col == VIEW_SIZE - 1)
			{
				printf("~ ");
			}
			else if(dy == 0 && dx == 0)
			{
				printf("%c ", user_graphic[user->facing]);
			}
			else
			{
				printf("%c ", GRID_GET(char, map->data, tile_row, tile_col, map->cols));
			}
		}
		printf("\n");
	}
}


void display_map_all(Grid* map, const Player* user){
	const char user_graphic[] = {
		[NORTH] = '^',
		[EAST] = '>',
		[SOUTH] = 'v',
		[WEST] = '<'
	};
	
	for(int row = 0; row < map->rows; row++)
	{
		for(int col = 0; col < map->cols; col++)
		{
			if(row == user->y_pos && col == user->x_pos){
				printf("%c ", user_graphic[user->facing]);
			}
			else
			{
				printf("%c ", GRID_GET(char, map->data, row, col, map->cols));
			}
		}
		printf("\n");
	}
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
