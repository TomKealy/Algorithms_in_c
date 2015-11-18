#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "List.h"

void List_init(List *list){
  
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  return;
}

List* Test_List_init() {
  
  List *test_list = malloc(sizeof(List));
  List_init(test_list);
  assert(test_list->head == NULL);
  assert(test_list->tail == NULL);
  assert(test_list->size == 0);
  return test_list;
}

int List_ins_next(List *list, ListElmt *element, const int data){
 
  ListElmt *new_element;
  
  //Allocate memory for the new_element -> check that mem has been allocated
  if((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
    return -1;
  
  new_element->data = data;
  //Add to the head
  if(element == NULL){
    if(List_size(list) == 0){
      //reset tail to point to new_element
      list->tail = new_element;
    }
    //set next of new_element to head
    new_element->next = list->head;

    //reset head to point to new_element
    list->head = new_element;
  }
  else{
    //check we're not adding after the tail
    if(element->next == NULL){
      list->tail = new_element;
    }
    //set next of new_element to whatever element points to
    new_element->next = element->next;
    
    //set element->next to new_emlement
    element->next = new_element;
  }
  
  list->size++;
  return 0;
}

int List_rem_next(List *list, ListElmt *element){
  /*
    Removes the list element after element
   */
  ListElmt *old_element;
  
  if(List_size(list) == 0)
    return -1;
 
  if(element == NULL){
    old_element = list->head;
    list->head = list->head->next;
    if(List_size(list) == 1)
      list->tail == NULL;
  }
  else{
    if(element->next == NULL)
      return -1;
    old_element = element->next;
    element->next = element->next->next;
    if(element->next == NULL)
      list->tail = element;
  }
  list->size--;

  free(old_element);
  return 0;
}


void List_print(List *list){
  ListElmt *curr = (ListElmt *)malloc(sizeof(ListElmt));
  curr = list->head;
  
  while(curr) {
    printf("%d\n", curr->data);
    curr = curr->next ;
  }
  free(curr);

  return;
}

void Test_List_ins_after_head(List *list, int value){
  
  //Add data after head
  List_ins_next(list, NULL, value);

  //Test that size increase
  assert(list->size == 1);

  //Test that the new data added is correct
  List_print(list);
  return;
}

void Test_List_ins_before_tail(List *list, int value){
  //Add data after tail
    
  List_ins_next(list, list->head, value);
  assert(list->size == 2);
  
  List_print(list);
  return;
}

void Test_List_ins(List *list, int value){
  
  ListElmt *element = (ListElmt *)malloc(sizeof(ListElmt));
  element = list->head; //points to 5
  
  List_ins_next(list, element, value);
  assert(list->size == 3);
  
  List_print(list);
  
  free(element);
  return;
}

void Test_List_rem_head(List *list){
    
  int *data = (int *)malloc(sizeof(int));
  List_rem_next(list, NULL, &data);
  assert(list->size == 2);

  List_print(list);

  return;
}

int main() {
  
  List *test_list = Test_List_init();
  
  Test_List_ins_after_head(test_list, 5);
  
  //Add element before tail
  Test_List_ins_before_tail(test_list, 15);
  
  //Add element between 5 and 15
  Test_List_ins(test_list, 10);

  //Remove 10
  //Test_List_rem_head(test_list);

  return 0;
}
