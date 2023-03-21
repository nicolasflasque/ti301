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

void testDisplaySimplelist(t_std_list);

/***
 * @brief
 * @param
 * @return
 */
int isEmptyList(t_std_list);

/***
 * @brief
 * @param
 * @return
 */
void displayStdList(t_std_list);

/***
 * @brief
 * @param
 * @return
 */
void displayHtList(t_ht_list);

/***
 * @brief
 * @param
 * @return
 */
int isEmptyHtList(t_ht_list);

/***
 * @brief
 * @param
 * @return
 */
void addHeadStd(t_std_list *, int);

/***
 * @brief
 * @param
 * @return
 */
void addHeadHt(t_ht_list *, int);

/***
 * @brief
 * @param
 * @return
 */
void addTailHt(t_ht_list *, int);

void insertOrderedHtList(t_ht_list *, int);

int isValInList(t_std_list, int);

void removeValFromList(t_std_list *, int);

void removeAllValFromList(t_std_list *, int);

int isValInHtList(t_ht_list, int);

void removeValFromHtList(t_ht_list *, int);

#endif //UNTITLED_LIST_H
