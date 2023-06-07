/*
Filename: Program2.c
Date: 02/20/2023
Author: Kaitlyn Clements
KUID: 3072622
Lab: 3
Last Modified: 02/20/2023
*/

#include <stdio.h>

void scorePossibilities(int score){
    /*
    tdc = Touch Down +2 points
    tdfg = Touch Down + Field Goal
    td = Touch Down
    fg = 3 point Field Goal
    sa = Safety
    */

   int tdc, tdfg, td, fg, sa;
        for (tdc = 0; tdc <= score / 8; tdc++){
            for (tdfg = 0; tdfg <= score/7; tdfg++){
                for (td = 0; td <= score/6; td++){
                    for (fg = 0; fg <= score/2; fg++){
                        for (sa = 0; sa <= score/2; sa++){
                            if ((tdc*8) + (tdfg*7) + (td*6) + (fg*3) + (sa*2) == score){
                                printf("%d Touch Down + 2points, %d Touch Down + Field Goal, %d Touch Down, %d 3 point Field Goal, %d Safety\n", tdc, tdfg, td, fg, sa);
                            }
                        }
                    }
                }
            }
        }
}

int main(void){
    int score; 
    while(1)
    {
        printf("\nEnter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score<=1){
            break;
        }
        scorePossibilities(score);
    }
}
