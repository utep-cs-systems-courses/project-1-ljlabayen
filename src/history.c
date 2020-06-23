#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history()  {
  List *history;
  history = (List*) malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str) {		      
  Item *new = (Item*)malloc(sizeof(Item));
  //if list is empty
  if (list->root == NULL){
    new->id = 1;
    list->root = new;
  // otherwise, list is not empty
  } else {
    Item *currItem = list->root;
    while(currItem->next != NULL) {
      currItem =  currItem->next;
    }
    // update id 
    new->id =  currItem->id + 1;
    currItem->next = new;
  }
  // new string is added to linked list
  new->str = str;
  new->next = NULL;
}

char *get_history(List *list, int id) {
  // check if list is empty
  if (list->root == NULL) {
    return "List is empty";
  } else {
    Item* temp = list->root;
    //traverse linked list
    while (temp != NULL) {
      if (temp->id == id) {
	return temp->str;
      }
      temp = temp->next;
    }
    return "Item ID not found\n";
  }
}

void print_history(List *list) {
  Item* temp = (list->root);
  // traverse linked list and print id and string
  while (temp != NULL) {
    printf("Item [%d]: %s \n", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list) {
  Item* temp;
  Item* temp2;
  temp2 = list->root;
  // keep track of next 
  while (temp2 != NULL) {
    temp =  temp2;
    temp2 = temp2->next;
    free(temp);
  }
  free(list);
}
