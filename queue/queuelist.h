//
// Created by flasque on 22/06/2022.
//

#ifndef UNTITLED_QUEUELIST_H
#define UNTITLED_QUEUELIST_H

#include "../base/list/list.h"

typedef struct s_qlist
{
    t_ht_list list;
} t_queuelist;

t_queuelist initEmptyQl();

int isEmptyQl(t_queuelist);

void displayQl(t_queuelist);

void enqueueQl(t_queuelist *, int);

int dequeueQl(t_queuelist *);

#endif //UNTITLED_QUEUELIST_H
