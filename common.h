#ifndef COMMON_H
#define COMMON_H
#define MAZE_SIZE 25

typedef enum
	{wall, path, start, m_exit}
block;

typedef enum
    {North, East, South, West}
direction;

struct player{
    int x_pos, y_pos;
    block blocks[3];
    direction facing;
};

#endif
