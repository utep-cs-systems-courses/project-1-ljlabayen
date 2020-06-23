#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()  {
  List *history;
  history = (List*) malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str) {		      
  Item *new = (Item*)malloc(sizeof(Item));
  if (list->root == 0){
    new->id = 1;
    list->root = new;
  } else {
    Item *currItem = list->root;
    while(currItem->next != NULL) {
      currItem =  currItem->next;
    }
    new->id =  currItem->id + 1;
    currItem->next = new;
  }
  new->str = str;
  new->next = NULL;
}
  
  /*if (list->root == NULL) {
    list->root = (Item*)malloc(sizeof(Item));
    list->root->id = 1;
    list->root->str = str;
    list->root->next = NULL;
  } else {
    Item* temp;
    temp = (list->root);
    while ((temp->next) != NULL) {
      temp = temp->next;
    }
    temp->next = (Item*) malloc(sizeof(Item));
    temp->next->id = temp->id + 1;
    temp->next->next = NULL;
  }
}
  */
char* get_history(List *list, int id) {
  if (list->root == NULL) {
    return "List is empty";
  } else {
    Item* temp = list->root;
    while (temp != NULL) {
      if (temp->id == id) {
	return temp->str;
      }
      temp = temp->next;
    }
    return "Item ID not found";
  }
}

void print_history(List *list) {
  Item* temp = (list->root);
  while (temp != NULL) {
    printf("Item [%d]: %s \n", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list) {
  Item* temp;
  Item* temp2;
  temp2 = list->root;
  while (temp2 != NULL) {
    temp =  temp2;
    temp2 = temp2->next;
    free(temp);
  }
  free(list);
}
