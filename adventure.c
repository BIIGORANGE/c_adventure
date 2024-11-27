#include <stdio.h>
#include <stdlib.h>


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
    char validDirection = '\0';
    char direction;

    //movement system, quit game
    while(direction != 'q'){
        printf("\ngive direction:");
        //reset validDirection
        char validDirection = '\0';
        //consumes newline character before processing next input
        while((validDirection = getchar()) != '\n') {
            if(validDirection == 'n' || validDirection == 's' || validDirection == 'w' || validDirection =='e') {
            direction = validDirection;
            break;
            }
            else {
            printf("please give valid input");
            break;
        }
        }
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
        else if(direction == 'e' && xCoordinate < 2){
            xCoordinate = xCoordinate + 1;
            printf(room[yCoordinate][xCoordinate]);
        }
        else if(direction == 'w' && xCoordinate > 0){
            xCoordinate = xCoordinate - 1;
            printf(room[yCoordinate][xCoordinate]);
        }
        else if (direction == 's' && yCoordinate >= 2 || direction == 'e' && xCoordinate >= 2) {
            printf("you can go no further\n");
            printf(room[yCoordinate][xCoordinate]);
        }
        else if (direction == 'n' && yCoordinate <= 0 || direction == 'w' && xCoordinate <= 0) {
            printf("you can go no further\n");
            printf(room[yCoordinate][xCoordinate]);
        }
        // clears input buffer up to newline
        while (getchar() != '\n');
    }
    return 0;
}