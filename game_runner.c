/**
*Author: Lloyd Jones
*Purpose: Is the games menu and graphics display
**/

#include <stdlib.h>
#include "all.h"

void player_runner(Grid* maze){
	TRACE("Start");
	Player 	user = {0};
	Action 	action = {0};
	CardinalDir move_dir = 0;
	char 	input[LINE_SIZE] = {0};
	int		error_flag = 0;

	get_start_coord(maze, &user.y_pos, &user.x_pos);
	
	do{
		display_maze(maze, &user);

		if(error_flag == 1)
		{
			display_input_error(input);
			error_flag = 0;
		}
		
		get_user_input(input);
		error_flag = parse_action_and_dir(input, &action.type, &action.rel_dir);
		
		if(error_flag == 0){
			if(action.type == TURN)
			{
				user.facing = ABS_DIR(user.facing, action.rel_dir);
			}
			else if(action.type == MOVE && (can_move_rel_dir(user.blocks, action.rel_dir)))
			{				
				move_dir = ABS_DIR(user.facing, action.rel_dir);
				move_player(move_dir, &user.y_pos, &user.x_pos);
			}
			update_player_blocks(maze, &user);
		}
	}while(GRID_GET(BlockType, maze->data, user.y_pos, user.x_pos, maze->cols) != M_EXIT);
    
    display_maze(maze, &user);
	free(maze->data);
}

