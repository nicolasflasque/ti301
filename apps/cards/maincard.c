//
// Created by flasque on 24/06/2022.
//
#include <stdlib.h>
#include <stdio.h>
#include "cards.h"
#include "../../circlist/circlist.h"
#include "../../utils/timer/timer.h"

#define DECK_SIZE 1000
#define NB_DIST 1000

p_cell _card;
t_card _deck[DECK_SIZE];
int *_distrib;
int _indeck;
t_circ_list _cl;

void initall()
{
    _distrib = (int *) calloc(DECK_SIZE, sizeof(int));
    _indeck = DECK_SIZE;
    _cl = createEmptyCircList();
    _card = NULL;
    for (int _initcpt = 0; _initcpt < DECK_SIZE; _initcpt++)
    {
        _distrib[_initcpt] = 0;
        _deck[_initcpt].rank = _initcpt;
        _deck[_initcpt].color = _initcpt;
        int h_or_t = rand() % 2;
        if (h_or_t)
        {
            insertValueHead(&_cl, _initcpt);
        } else
        {
            insertValueTail(&_cl, _initcpt);
        }
    }
}

int main()
{
    startTimer();
    for (int runs = 0; runs < NB_DIST; runs++)
    {
        initall();
    }
    stopTimer();
    printf("init time : ");
    displayTime();

    startTimer();
    for (int runs = 0; runs < NB_DIST; runs++)
    {
        initall();
        while (_indeck > 0)
        {

            if (!isEmptyHtList(_cl))
            {
                _card = _cl.head;

                removeCell(&_cl, _card);
                _indeck--;
            }

        }
    }
    stopTimer();
    printf("distribution avec ht_list : ");
    displayTime();
    int picks = 0;

    startTimer();
    for (int runs = 0; runs < NB_DIST; runs++)
    {

        initall();
        while (_indeck > 0)
        {
            int idx;
            do
            {
                idx = rand() % DECK_SIZE;
                picks++;
            } while (_distrib[idx] != 0);

            _distrib[idx] = 1;
            _indeck--;

        }
    }
    stopTimer();
    printf("distribution avec tableau (%d picks) : ", picks / NB_DIST);
    displayTime();
    return 0;
}