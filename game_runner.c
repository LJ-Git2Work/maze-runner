/**
*Author: Lloyd Jones
*Purpose: Is the games menu and graphics display
**/

#include <stdlib.h>
#include "all.h"

void player_runner(Grid* maze){
	TRACE("Start");
	Grid 	map_view = {0};	
	Player 	user = {0};
	Action 	action = {0};
	CardinalDir move_dir = 0;
	char 	input[LINE_SIZE] = {0};
	int		error_flag = 0;
	
	TRACE("Start grid mem allocation");
	grid_init(&map_view, VIEW_SIZE, VIEW_SIZE, sizeof(char));
	TRACE("Map view initialised");
	
	get_start_coord(maze, &user.y_pos, &user.x_pos);
	
	do{
		system("cls");
		create_map_view(maze, &user, &map_view);
		display_map_view(&map_view);
		
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
    
    display_map_view(&map_view);
	
	free(maze->data);
	free(map_view.data);
}

