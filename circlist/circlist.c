//
// Created by flasque on 23/06/2022.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "circlist.h"

void displayCircListStatus(int status)
{
    switch (status)
    {
        case 1 :
            fprintf(stderr, "list is ok\n");
            break;
        case 0 :
            fprintf(stderr, "list is not ok : head is NULL, tail is NOT NULL\n");
            break;
        case -1 :
            fprintf(stderr, "list is not ok : head is NOT NULL, tail is NULL\n");
            break;
        case -2 :
            fprintf(stderr, "list is not circular : the next of the tail is not the head\n");
            break;
        case -3 :
            fprintf(stderr, "list is not ok : number of cells is not correct\n");
    }
    return;
}

int checkIsCircList(t_circ_list cl, int awaited_size)
{
    // status 1 : ok
    int size = 0;
    // -1 si l'un des deux est NULL et pas l'autre
    if ((cl.head == NULL) && (cl.tail != NULL))
    {
        return 0;
    }
    if ((cl.head != NULL) && (cl.tail == NULL))
    {
        return -1;
    }
    // -2 si la dernière ne repointe pas sur la première
    if (cl.head != NULL)
    {
        if (cl.tail->next != cl.head)
        {
            return -2;
        } else
        {
            while (cl.head != cl.tail)
            {
                size += 1;
                cl.head = cl.head->next;
            }
            size += 1;

            if (size != awaited_size)
            {
                return -3;
            }
        }
    } else
    {
        if (awaited_size != 0)
        {
            return -3;
        }
    }


    return 1;
}

t_circ_list createEmptyCircList()
{
    t_circ_list cl;
    cl.head = NULL;
    cl.tail = NULL;

    return cl;
}


void insertValueHead(t_circ_list *p_cl, int value)
{
    p_cell nouv = createCell(value);
    if (isEmptyHtList(*p_cl))
    {
        p_cl->head = p_cl->tail = nouv;
        p_cl->tail->next = p_cl->head;
    } else
    {
        nouv->next = p_cl->head;
        p_cl->head = nouv;
        p_cl->tail->next = p_cl->head;
    }

    return;
}

void insertValueTail(t_circ_list *p_cl, int value)
{
    p_cell nouv = createCell(value);
    if (isEmptyHtList(*p_cl))
    {
        p_cl->head = nouv;
        p_cl->tail = nouv;
        p_cl->tail->next = p_cl->head;
    } else
    {
        nouv->next = p_cl->head;
        p_cl->tail->next = nouv;
        p_cl->tail = p_cl->tail->next;
    }

    return;

}

void displayCircList(t_circ_list cl)
{
    p_cell head = cl.head;
    p_cell savehead;
    char whole[6][1000];
    char displayStr[1000] = "";
    char spaces[1000] = "";
    char buffer[50];
    int tailPos;
    int posLoop = 17;
    int posBack;
    int over = 0;

    if (head == NULL)
    {
        savehead = NULL;
    } else
    {
        savehead = cl.tail->next;
    }

    for (int spcpt = 0; spcpt < 999; spcpt++)
    {
        spaces[spcpt] = ' ';
    }
    spaces[999] = '\0';

    strcat(displayStr, "list [head @-]-->");
    if (head == NULL)
    {
        displayStr[strlen(displayStr)] = 'N';
        displayStr[strlen(displayStr)] = 'U';
        displayStr[strlen(displayStr)] = 'L';
        displayStr[strlen(displayStr)] = 'L';
        displayStr[strlen(displayStr)] = '\n';
        tailPos = 17;
    } else
    {
        while (head != NULL && !over)
        {
            sprintf(buffer, "[ %d | @-]-->", head->value);
            strcat(displayStr, buffer);
            if (head->next == savehead)
            {
                displayStr[strlen(displayStr) - 1] = '/';
                char num[50];
                sprintf(num, "%d", head->value);
                tailPos = strlen(displayStr) - 11 - strlen(num);
                over = 1;
            }
            head = head->next;
        }

        displayStr[strlen(displayStr)] = '\n';
    }

    strcpy(whole[3], displayStr);
    posBack = strlen(displayStr) - 2;


    spaces[tailPos] = '^';
    spaces[tailPos + 1] = '\n';
    spaces[tailPos + 2] = '\0';
    strcpy(whole[4], spaces);
    spaces[tailPos++] = '|';
    spaces[tailPos++] = '_';
    spaces[tailPos++] = '_';
    spaces[tailPos++] = '@';
    spaces[tailPos++] = ' ';
    spaces[tailPos++] = 'l';
    spaces[tailPos++] = 'i';
    spaces[tailPos++] = 's';
    spaces[tailPos++] = 't';
    spaces[tailPos++] = ' ';
    spaces[tailPos++] = '[';
    spaces[tailPos++] = 't';
    spaces[tailPos++] = 'a';
    spaces[tailPos++] = 'i';
    spaces[tailPos++] = 'l';
    spaces[tailPos++] = ']';


    spaces[tailPos] = '\n';
    strcpy(whole[5], spaces);

    for (int spcpt = 0; spcpt < 999; spcpt++)
    {
        spaces[spcpt] = ' ';
    }
    spaces[999] = '\0';

    spaces[posLoop] = 'v';
    spaces[posBack] = '|';
    spaces[posBack + 1] = '\n';
    spaces[posBack + 2] = '\0';

    strcpy(whole[2], spaces);
    spaces[posLoop] = '|';
    strcpy(whole[1], spaces);

    for (int cpt = posLoop; cpt <= posBack; cpt++)
    {
        spaces[cpt] = '_';
    }

    strcpy(whole[0], spaces);

    int base = 3 * (cl.head == NULL);

    for (int cpt = base; cpt < 6; cpt++)
    {
        printf("%s", whole[cpt]);
    }
    printf("\n");
    return;
}

void removeCell(t_circ_list *p_cl, p_cell out)
{
    p_cell tmp = out;

    if (isEmptyHtList(*p_cl))
    {
        printf("cannot remove a cell from an empty list\n");
    } else
    {
        // process apart a list with only on element
        // where head and tail are equal
        if (p_cl->head == p_cl->tail)
        {
            *p_cl = createEmptyCircList();
        } else // find prev (previous to 'out')
        {
            p_cell prev = p_cl->head;
            while (prev->next != out)
            {
                prev = prev->next;
            }
            // prev points to the cell 'prev' the one to remove

            // if we are to remove the 'tail' cell
            if (p_cl->tail == out)
            {
                prev->next = out->next;
                p_cl->tail = prev;
            } else
            {
                if (p_cl->head == out)
                {
                    p_cl->head = p_cl->head->next;
                    p_cl->tail->next = p_cl->head;
                } else
                {
                    prev->next = out->next;
                }
            }
        }
        // 'delete' the tmp=out cell from available memory
        free(tmp);
    }

    return;

}

void removeCellCircList(t_circ_list *p_list, int val)
{
    p_cell temp, prev;

    if (p_list->head != NULL)
    {
        if ((p_list->head == p_list->tail) && (p_list->head->value == val))
        {
            p_list->head = p_list->tail = NULL;
        } else
        {
            temp = prev = p_list->head;

            while ((temp->next != p_list->head) && (temp->value != val))
            {
                prev = temp;
                temp = temp->next;
            }

            if (temp->value == val) // on a trouve la cellule !
            {
                if (temp == p_list->head)
                {
                    p_list->head = p_list->head->next;
                    p_list->tail->next = p_list->head;
                } else
                {
                    prev->next = temp->next;
                }
            }

            if (p_list->tail->value == val)
            {
                prev->next = temp->next;
                p_list->tail = prev;
            }
        }
    }

    return;
}
