/**
*Author: Lloyd Jones
*Purpose: Is the games menu header
**/
#ifndef INPUT_OUTPUT
#define INPUT_OUTPUT

int menu();
void get_user_input(char* input);
void display_input_error(const char* input);

/********************	GRAPHICS	********************/
void create_and_display_maze(const Grid* maze, const Player* user);
void create_map(const Grid* maze, Grid* map);
void display_player_map(Grid* map, const Player* user);
void display_map_all(Grid* map, const Player* user);
//char get_block_graphic(BlockType item);
//char get_user_graphic(CardinalDir facing);
    
#endif