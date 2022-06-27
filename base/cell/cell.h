//
// Created by flasque on 16/06/2022.
//

#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H

struct s_cell
{
    int value;
    struct s_cell *next;
};

typedef struct s_cell t_cell, *p_cell;

void displayCell(t_cell);

p_cell createCell(int val);

#endif //UNTITLED_CELL_H
