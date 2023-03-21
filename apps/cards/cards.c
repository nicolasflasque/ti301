//
// Created by flasque on 24/06/2022.
//

#include <stdio.h>
#include "cards.h"

void displayCard(int cardnumber)
{
    int col, haut;

    col = cardnumber/4;
    haut = cardnumber % 13;
    char names[13][3]=
            {
                    "2","3","4","5","6","7","8","9","10","J","Q","K","A"
            };

    char spades[]={226,153,160,0};
    char clubs[] = {226, 153, 163,0};
    char hearts[] = {226, 153, 165,0};
    char diamonds[] = {226, 153, 166,0};

    printf("%s ",names[haut]);
    switch(col)
    {
        case 0 :
            printf("%s\n", clubs);
            break;
        case 1 :
            printf("%s\n", diamonds);
            break;
        case 2 :
            printf("%s\n", hearts);
            break;
        case 3 :
            printf("%s\n", spades);
            break;
    }

    return;
}