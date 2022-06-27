//
// Created by flasque on 21/06/2022.
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H

#include "../base/list/list.h"

typedef struct s_stack
{
    t_std_list list;
} t_stack;

void displayStack(t_stack);

t_stack emptyStack();

int isStackEmpty(t_stack);

void push(t_stack *, int);

int top(t_stack);

int pop(t_stack *);

#endif //UNTITLED_STACK_H
