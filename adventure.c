#include <stdio.h>

int main(void) {
    //setup 2d array to create a 3x3 room that the player can navigate in
    const char * room[][3] = {
        {"top_l","top_m","top_r"},
        {"mid_l","mid_m","mid_r"},
        {"bot_l","bot_m","bot_r"}
        };
    //move to other rooms from starting room[0][0]
    //(x,y) notation flipped (y,x) for 2d arrays. First number is row(y) second is column(x)
    int yCoordinate = 0;
    int xCoordinate = 0;

    printf(room[yCoordinate][xCoordinate]);

    char direction = 'n';

//movement system, quit game
    while(direction != 'q'){
    printf("\ngive direction: ");
    scanf("\n %c", &direction);
        if(direction == 's'){
            yCoordinate = yCoordinate + 1;
            printf(room[yCoordinate][xCoordinate]);
        }
        else if(direction == 'n'){
            yCoordinate = yCoordinate - 1;
            printf(room[yCoordinate][xCoordinate]);
        }
        //going too far to the 'e' direction has the array skip to the next set in line. so at room[0][2] + 'e' = room[1][0]. not sure why it does this. same in the opposite direction 'w'
        else if(direction == 'e'){
            xCoordinate = xCoordinate + 1;
            printf(room[yCoordinate][xCoordinate]);
        }
        else if(direction == 'w'){
            xCoordinate = xCoordinate - 1;
            printf(room[yCoordinate][xCoordinate]);
        }
        else if(direction == 'q'){
            printf("Goodbye!");
        }
        else{
            printf("Please give one of the following: 'n','s','w','e'");
        }
    }
    //need to figure out how to stop players if room[2][2] or room[0][0] to avoid seg fault. how do you set a max and min? another if statement seems messy

}
