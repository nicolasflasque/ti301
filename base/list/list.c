//
// Created by flasque on 18/06/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

void testDisplaySimplelist(t_std_list aList)
{
    printf("[");
    p_cell temp = aList.head;
    while (temp != NULL)
    {
        printf("%d | ",temp->value);
        temp=temp->next;
    }
    printf("NULL]\n");
}

int isValInList(t_std_list aList, int val)
{
    int res = 0;
    p_cell temp = aList.head;
    while ((temp != NULL) && (temp->value != val))
    {
        temp = temp->next;
    }

    if (temp != NULL)
    {
        res = 1;
    }

    return res;
}

void removeValFromList(t_std_list *p_list, int val)
{
    p_cell temp;
    p_cell prev;

    int found=0;

    if (p_list->head != NULL)
    {
        temp = p_list->head;
        prev = temp;

        if ((temp->value)==val)
        {
            p_list->head = temp->next;
            // optionnel
            free(temp);
        }
        else
        {
            while ((temp != NULL ) && (temp->value != val))
            {
                prev=temp;
                temp = temp->next;
            }

            if (temp != NULL)
            {
                prev->next = temp->next;
                //optionnel
                free(temp);
            }
        }
    }

    return;
}

void removeAllValFromList(t_std_list *p_list, int val)
{
    while (isValInList(*p_list, val) == 1)
    {
        removeValFromList(p_list, val);
    }
    return;
}


void insertOrderedHtList(t_ht_list *p_list, int val)
{
    p_cell temp;
    p_cell prev;
    p_cell nouv;

    nouv = createCell(val);

    if (isEmptyHtList(*p_list))
    {
        p_list->head = p_list->tail = nouv;
    }
    else
    {
        temp = p_list->head;
        prev = temp;

        while ((temp != NULL) && (temp->value < nouv->value))
        {
            prev = temp;
            temp = temp->next;
        }

         if (temp == prev)
        {
            nouv->next = p_list->head;
            p_list->head = nouv;
        }
        else
        {
            nouv->next = temp;
            prev->next = nouv;

            if (temp==NULL)
            {
                p_list->tail = nouv;
            }
        }
    }

    return;
}

void addHeadStd(t_std_list *p_list, int val)
{
    p_cell nouv;
    nouv = createCell(val);
    nouv->next = p_list->head;
    p_list->head = nouv;

    return;
}

void displayStdList(t_std_list list)
{
    p_cell head = list.head;
    // first : display @-->
    printf("list [head @-]-->");
    if (head == NULL)
    {
        printf("NULL");
    } else
    {
        while (head != NULL)
        {
            displayCell(*head);
            head = head->next;
        }
    }

    printf("\n");

    return;
}

void addHeadHt(t_ht_list *p_list, int val)
{
    p_cell nouv;
    nouv = createCell(val);

    if (p_list->head == NULL)
    {
        p_list->tail = nouv;
    }

    nouv->next = p_list->head;
    p_list->head = nouv;

    return;
}

void addTailHt(t_ht_list *p_list, int val)
{
    p_cell nouv;
    nouv = createCell(val);

    if (p_list->head == NULL)
    {
        addHeadHt(p_list, val);
    } else
    {
        p_list->tail->next = nouv;
        p_list->tail = nouv;
    }

    return;
}

void displayHtList(t_ht_list list)
{
    p_cell head = list.head;
    char displayStr[1000] = "";
    char spaces[1000] = "";
    char buffer[50];
    int tailPos;

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
        while (head != NULL)
        {
            sprintf(buffer, "[ %d | @-]-->", head->value);
            strcat(displayStr, buffer);
            if (head->next == NULL)
            {
                char num[50];
                sprintf(num, "%d", head->value);
                tailPos = strlen(displayStr) - 11 - strlen(num);
            }
            head = head->next;
        }

        displayStr[strlen(displayStr)] = 'N';
        displayStr[strlen(displayStr)] = 'U';
        displayStr[strlen(displayStr)] = 'L';
        displayStr[strlen(displayStr)] = 'L';
        displayStr[strlen(displayStr)] = '\n';

    }

    spaces[tailPos] = '^';
    spaces[tailPos + 1] = '\n';
    spaces[tailPos + 2] = '\0';
    strcat(displayStr, spaces);
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


    spaces[tailPos++] = '\n';
    spaces[tailPos] = '\0';

    strcat(displayStr, spaces);

    printf("%s\n", displayStr);

    return;
}

int isEmptyList(t_std_list l)
{
    return l.head == NULL;
}

int isEmptyHtList(t_ht_list htl)
{
    int res = 0;
    if ((htl.head == NULL) != (htl.tail == NULL))
    {
        printf("CRITICAL ERROR : head and tail should both be NULL or initialized\n");
        exit(-1);
    } else
    {
        if (htl.head == NULL)
        {
            res = 1;
        }
    }

    return res;
}

int isValInHtList(t_ht_list list, int val)
{
    p_cell temp = list.head;
    int found = 0;

    while ((temp != NULL) && (val != temp->value))
    {
        temp = temp->next;
    }

    if (temp != NULL)
    {
        found = 1;
    }

    return found;
}

void removeValFromHtList(t_ht_list *p_list, int val);
