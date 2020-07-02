#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history()  {
  //  List *history;
  List *list = (List *)malloc(sizeof(List));
  list->root = NULL;
}

int str_len(char *str) {
  int i = 0;
  int count = 0;

  while(str[i] != '\0'){
    i++;
    count++;
  }
  return count;
}    
void add_history(List *list, char *str) {
  Item *new_item = (Item *)malloc(sizeof(Item)); //initialize new item and allocate memory
  Item *temp = list->root; // temporary node
  
  new_item->str = copy_str(str, str_len(str)); // use copy_str to copy 
  new_item->next=NULL;
  // if list is empty
  if (list->root == NULL) {
    list->root = new_item;
    new_item->id = 1; // set id to 1

  } else {
    while(temp->next != NULL) { // iterate to the end of the list
      new_item->id++; 
      temp = temp->next; // move to next item
    }

    temp->next = new_item; // add new item
    new_item->id = temp->id + 1; // new item id
  }
}
 
char *get_history(List *list, int id) {
  // check if list is empty
  if (list->root == NULL) {
    return "List is empty";
  } else {
    Item* temp = list->root;
    
    while (temp != NULL) { // traverse linked list
      if (temp->id == id) {
	return temp->str;
      }
      temp = temp->next;
    }
    return "Item ID not found\n"; // if given id is not found
  }
}

void print_history(List *list) {
  Item *temp = list->root;
  // traverse linked list and print id and string
  while (temp != NULL) {
    printf("Item [%d]: %s \n", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list) {
  Item* temp; // temporary pointers
  Item* temp2;
  temp2 = list->root;
  // traverse linked list and keep track of next 
  while (temp2 != NULL) {
    temp =  temp2;
    temp2 = temp2->next;
    free(temp);
  }
  free(list);
}
