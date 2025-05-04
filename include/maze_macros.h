#ifndef MAZE_MACROS
#define MAZE_MACROS

#define VIEW_SIZE 11
#define LINE_SIZE 100

#define MAZE_CURSOR "maze> "
#define MENU_CURSOR "menu> "

#define TRACE(msg) (fprintf(stderr, "[::%s::] {::%s::}\n", __func__, msg))
#define VARTRACE(var, type) \
	(fprintf(stderr, "[::%s::] {%s = " type "}\n", __func__, #var, var))

#define ABS_DIR(card, rel) ((card + rel) % 4)

#define GRID_GET(type, grid, row, col, col_max) \
	(((type *)(grid))[(row) * col_max + (col)])

#define GRID_SET(type, grid, row, col, col_max, value) \
	(GRID_GET(type, grid, row, col, col_max) = (value))
	
#endif
