#ifndef MAZE_STRUCTS
#define MAZE_STRUCTS

/* The four types of blocks */
typedef enum{
	WALL, 
	PATH, 
	START, 
	M_EXIT
}BlockType;

/* The four cardinal directions the player can face */
typedef enum{
	NORTH = 0, 
	EAST = 1, 
	SOUTH = 2, 
	WEST = 3
}CardinalDir;

/* The users relative direction */
typedef enum{
	FRONT = 0,
	RIGHT = 1,
	BACK = 2,
	LEFT = 3,
	INVALID_DIR = 4
}RelativeDir;


/* The 7 actions the player can make, and default */
typedef enum{
	MOVE = 0,
	TURN = 1,
	INVALID_ACTION = 2
}ActionType;


/* The action a player can take is of a type and in a relative direction to themself */
typedef struct{
	ActionType type;
	RelativeDir rel_dir;
}Action;

typedef enum{
	BOT,
	HUMAN
}Identity;

/* The player structure, their position in the maze structure, the cardinal direction they are facing */
typedef struct{
    int x_pos, y_pos;
	BlockType blocks[4];
    CardinalDir facing;
	Identity identity;
}Player;


#endif
