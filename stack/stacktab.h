//
// Created by flasque on 21/06/2022.
//

#ifndef UNTITLED_STACKTAB_H
#define UNTITLED_STACKTAB_H

#define MAX_SIZE 50

typedef struct s_tab
{
    int values[MAX_SIZE];
    int nbElts;
} t_tab;

typedef struct s_stacktab
{
    t_tab tab;
} t_stacktab;

t_stacktab initEmptySt();

void displayStacktab(t_stacktab);

int isEmptySt(t_stacktab);

void pushSt(t_stacktab *, int);

int topSt(t_stacktab);

int popSt(t_stacktab *);

#endif //UNTITLED_STACKTAB_H
