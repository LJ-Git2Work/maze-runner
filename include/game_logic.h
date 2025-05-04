/**
*Author: Lloyd Jones
*Purpose: Is the games Logic, i.e. -positioning
**/

#ifndef MAZE_LOGIC
#define MAZE_LOGIC

/********************	POSITIONING	********************/

void get_start_coord(const Grid* maze, int* y, int* x);

int parse_action_and_dir(const char* input, ActionType* type, RelativeDir* rel_dir);

CardinalDir parse_ActionType(const char* string);
RelativeDir parse_RelativeDir(const char* string);

void move_player(const CardinalDir facing, int* y_pos, int* x_pos);

int can_move_rel_dir(const BlockType *surrounding_blocks, RelativeDir rel_dir);

//CardinalDir get_absolute_direction(const CardinalDir facing, const RelativeDir rel_dir);

void update_player_blocks(Grid* maze, Player* user);
#endif