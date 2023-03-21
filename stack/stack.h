//
// Created by flasque on 21/06/2022.
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H

#include "../base/list/list.h"

typedef  t_std_list  t_stack_list;

void displayStack(t_stack_list);

t_stack_list emptyStack();

int isStackEmpty(t_stack_list);

void push(t_stack_list *, int);

int top(t_stack_list);

int pop(t_stack_list *);

#endif //UNTITLED_STACK_H
