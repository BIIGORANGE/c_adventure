#include <stdio.h>

int main(void) {
    //setup 2d array to create a 3x3 room that the player can navigate in
    const char * room[][3] = {
        {"top_l","top_m","top_r"},
        {"mid_l","mid_m","mid_r"},
        {"bot_l","bot_m","bot_r"}
        };
    //(x,y) notation flipped (y,x) for 2d arrays. First number is row(y) second is column(x)
    int yCoordinate = 0;
    int xCoordinate = 0;

    printf(room[yCoordinate][xCoordinate]);

    char direction;

    //movement system, quit game
    while(direction != 'q'){
    printf("\ngive direction: ");
    scanf("\n %c", &direction);
        //entering multiple of the same character will +1(-1) the array that many times. for example, "Give direction: ee" > xCoordinate + 2. or "Give direction: www" > xCoordinate -3.
        if(direction == 'q'){
            printf("Goodbye!");
        }
        else if(direction == 's' && yCoordinate < 2){
            yCoordinate = yCoordinate + 1;
            printf(room[yCoordinate][xCoordinate]);
        }
        else if(direction == 'n' && yCoordinate > 0){
            yCoordinate = yCoordinate - 1;
            printf(room[yCoordinate][xCoordinate]);
        }
        //going too far to the 'e' direction has the array skip to the next set in line. so at room[0][2] + 'e' = room[1][0]. not sure why it does this. same in the opposite direction 'w'
        else if(direction == 'e' && xCoordinate < 2){
            xCoordinate = xCoordinate + 1;
            printf(room[yCoordinate][xCoordinate]);
        }
        else if(direction == 'w' && xCoordinate > 0){
            xCoordinate = xCoordinate - 1;
            printf(room[yCoordinate][xCoordinate]);
        }
        else if (direction == 's' && yCoordinate >= 2) {
            printf("you can go no further\n");
            printf(room[yCoordinate][xCoordinate]);
        }
        else if (direction == 'n' && yCoordinate <= 0) {
            printf("you can go no further\n");
            printf(room[yCoordinate][xCoordinate]);
        }
        else if (direction == 'e' && xCoordinate >= 2) {
            printf("you can go no further\n");
            printf(room[yCoordinate][xCoordinate]);
        }
        else if (direction == 'w' && xCoordinate <= 0) {
            printf("you can go no further\n");
            printf(room[yCoordinate][xCoordinate]);
        }
        else{
            printf("Please give one of the following: 'n','s','w','e'");
        }
    }
    //need to figure out how to stop players if room[2][2] or room[0][0] to avoid seg fault. how do you set a max and min? another if statement seems messy
    return 0;
}