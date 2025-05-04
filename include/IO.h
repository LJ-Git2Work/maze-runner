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
void display_maze(const Grid* maze, Player* user);
void create_map_view(const Grid* maze, const Player* user, Grid* map_view);
void display_map_view(Grid* map_view);
char get_block_graphic(BlockType item);
char get_user_graphic(CardinalDir facing);
    
#endif