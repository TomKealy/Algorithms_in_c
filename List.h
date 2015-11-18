#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/* Struct for List elements  */

typedef struct ListElmt_ {

  int             data;
  struct ListElmt_ *next;

} ListElmt;

/* Struct for Lists */

typedef struct List_ {

  int size;
  ListElmt *head;
  ListElmt *tail;

} List;

/* Public Interface */

void List_init(List* list);

//void List_destroy(List *list);

int List_ins_next(List *list, ListElmt *element, const int data);

void List_print(List *list);

int List_rem_next(List *list, ListElmt *element);

#define List_size(list) ((list)->size)

#define List_head(list) ((list)->head)

#define List_tail(list) ((list)->tail)

#define List_is_head(list, element) ((element) == (list)->head ? 1 : 0)

#define List_is_tail(element) ((element)->next == NULL ? 1 : 0)

#define List_data(element) ((element)->data)

#define List_next(element) ((element)->next)

#endif
