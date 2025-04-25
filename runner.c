#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "maze_runner.h"
#include "All_Functions.h"
/*
void display_direction(direction *facing){
    switch(*facing){
        case North:
            printf("North\n");
            break;
        case South:
            printf("South\n");
            break;
        case West:
            printf("West\n");
            break;
        case East:
            printf("East\n");
        }
}
*/
void player_runner(block (*block_maze)[MAZE_SIZE]){

    struct player user;
    get_start_coord(block_maze, &user.y_pos, &user.x_pos);
    user.facing = North;
    user.blocks[0] = path;
    user.blocks[1] = wall;
    user.blocks[2] = wall;
    //display_view(block_maze, user.facing, user.y_pos, user.x_pos);
    //display_graphics(user.blocks[0], user.blocks[1], user.blocks[2]);

    char action[20];
    
    do{
        user.blocks[0] = get_block(block_maze, user.facing, user.y_pos, user.x_pos);
        user.blocks[1] = get_block(block_maze, ((user.facing + 3) % 4), user.y_pos, user.x_pos);
        user.blocks[2] = get_block(block_maze, ((user.facing + 1) % 4), user.y_pos, user.x_pos);
        
        display_view(block_maze, user.facing, user.y_pos, user.x_pos);
        //display_graphics(user.blocks[0], user.blocks[1], user.blocks[2]);
        //printf("\nrow = %d, col = %d\n", user.y_pos, user.x_pos);

        printf("\n>> ");
        fgets(action, sizeof(action), stdin);
        action[strcspn(action, "\n")] = '\0';

        system("cls");

        if(stricmp(action, "move") == 0 && user.blocks[0] != wall){
            move_direction(user.facing, &user.x_pos, &user.y_pos);
        }else if(strcmp(action, "turn left") == 0){
            user.facing = (user.facing + 3) % 4; 
        }else if(strcmp(action, "turn right") == 0){
            user.facing = (user.facing + 1) % 4; 
        }

    }while(block_maze[user.y_pos][user.x_pos] != m_exit);
    
    display_view(block_maze, user.facing, user.y_pos, user.x_pos);
    
    printf("You win!!!!!!!!");
}

