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
  if (list->root == NULL) {
    list->root = (Item*) malloc(sizeof(Item));
    list->root = id = 1;
    list->root->str = str;
    list->root->next = NULL;
  } else {
    Item* temp;
    temp = (list->root);
    while ((temp->next) != NULL) {
      temp = temp->next;
    }
    temp->next = (Item*) malloc(sizeof(Item));
    temp->next->id = ((*temp).id) + 1;
    temp->next->next = NULL;
  }
}
