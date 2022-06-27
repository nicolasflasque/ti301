//
// Created by flasque on 18/06/2022.
//

#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H

#include "../cell/cell.h"

typedef struct s_std_list
{
    p_cell head;
} t_std_list;

typedef struct s_ht_list
{
    p_cell head;
    p_cell tail;
} t_ht_list;

int isEmptyList(t_std_list);

void displayStdList(t_std_list);

void displayHtList(t_ht_list);

int isEmptyHtList(t_ht_list);

void addHeadStd(t_std_list *, int);

void addHeadHt(t_ht_list *, int);

void addTailHt(t_ht_list *, int);

#endif //UNTITLED_LIST_H
