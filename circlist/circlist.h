//
// Created by flasque on 23/06/2022.
//

#ifndef UNTITLED_CIRCLIST_H
#define UNTITLED_CIRCLIST_H

#include "../base/list/list.h"

typedef t_ht_list t_circ_list;

void displayCircList(t_circ_list);

t_circ_list createEmptyCircList();

void insertValueHead(t_circ_list *, int);

void insertValueTail(t_circ_list *, int);

void removeCell(t_circ_list *, p_cell);

#endif //UNTITLED_CIRCLIST_H
