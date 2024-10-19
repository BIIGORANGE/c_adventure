#include <stdio.h>

int main(void) {
    //setup 2d array to create a 3x3 room that the player can navigate in
    const char * room[][3] = {
        {"top_l","top_m","top_r"},
        {"mid_l","mid_m","mid_r"},
        {"bot_l","bot_m","bot_r"}
        };
    //move to other rooms from starting room[0][0]
    int yCoordinate = 0;
    int xCoordinate = 0;
  
    
    scanf("%d", &xCoordinate);
    scanf("%d", &yCoordinate);

    // (x,y) notation flipped (y,x) for 2d arrays. First number is column(y) second is row (x)
    printf(room[yCoordinate][xCoordinate]);

 }
