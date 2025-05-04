/**
*Author: Lloyd Jones
*Purpose: Is the games Logic, i.e. -positioning
**/

#include <string.h>
#include "all.h"

/********************	POSITIONING	********************/

void get_start_coord(const Grid* maze, int* y, int* x){
	for(int row = 0; row < maze->rows; row++)
	{
		for(int col = 0; col < maze->cols; col++)
		{
			if(GRID_GET(BlockType, maze->data, row, col, maze->cols) == START){
				//TRACE("Start position found");
				*y = row;
				*x = col;
				return;
			}
		}
	}
}

int parse_action_and_dir(const char* input, ActionType* type, RelativeDir* rel_dir){
	char string[LINE_SIZE];
	char* string_ptr;
	strcpy(string, input);
	string[strcspn(string, "\n")] = '\0';
	
	string_ptr = strtok(string, " ");
	
	if(string_ptr == NULL){
		*type = INVALID_ACTION;
		//TRACE("USER INPUT = INVALID ACTION");
	}
	else{
		*type = parse_ActionType(string_ptr);
	}
	
	string_ptr = strtok(NULL, " ");
	
	if(string_ptr == NULL){
		*rel_dir = FRONT;
		//TRACE("USER MOVE DIR POINTER = NULL");
	}
	else{
		*rel_dir = parse_RelativeDir(string_ptr);
		//fprintf(stderr, "string {%s}\n", string_ptr);
		//fprintf(stderr, "%d direction \n", *rel_dir);
	}

	return(*type == INVALID_ACTION || *rel_dir == INVALID_DIR);
}

CardinalDir parse_ActionType(const char *string){
	if(strncmp(string, "move", 4) == 0) return MOVE;
	if(strncmp(string, "turn", 4) == 0) return TURN;
	return INVALID_ACTION;
}

RelativeDir parse_RelativeDir(const char *string){
	if(strcmp(string, "forward") == 0) return FRONT;
	if(strcmp(string, "right") == 0) return RIGHT;
	if((strcmp(string, "back") == 0) || (strcmp(string, "backward") == 0)) return BACK;
	if(strcmp(string, "left") == 0) return LEFT;
	return INVALID_DIR;
}

void move_player(const CardinalDir facing, int *y_pos, int *x_pos){
	const int dy[] = { -1, 0, 1, 0 };  
	const int dx[] = { 0, 1, 0, -1 };

	*y_pos = *y_pos + dy[facing];
	*x_pos = *x_pos + dx[facing];

	//switch(facing){
		//case NORTH: 	*y_pos = *y_pos - 1; 	/* printf("Move North\n"); */	return;
        //case SOUTH:		*y_pos = *y_pos + 1;  	/* printf("Move South\n"); */	return;
        //case WEST:		*x_pos = *x_pos - 1; 	/* printf("Move West\n"); */ 	return;
        //case EAST:		*x_pos = *x_pos + 1; 	/* printf("Move East\n"); */	return;
    //}
}

int can_move_rel_dir(const BlockType *surrounding_blocks, RelativeDir rel_dir){
	return(surrounding_blocks[rel_dir] != WALL);
}

/*
CardinalDir get_absolute_direction(CardinalDir facing, RelativeDir rel_dir) {
	return(facing + rel_dir) % 4;
}
*/

void update_player_blocks(Grid* maze, Player* user){
	const int dy[] = { -1, 0, 1, 0 };  
	const int dx[] = { 0, 1, 0, -1 };
	
	int y = user->y_pos;
	int x = user->x_pos;
	
	CardinalDir abs_facing = user->facing;
	CardinalDir abs_d;
	
	for(RelativeDir rel_dir = FRONT; rel_dir < INVALID_DIR; rel_dir++){
		abs_d = ABS_DIR(abs_facing, rel_dir);
		user->blocks[rel_dir] = GRID_GET(BlockType, maze->data, (y + dy[abs_d]), (x + dx[abs_d]), maze->cols);
	}
}