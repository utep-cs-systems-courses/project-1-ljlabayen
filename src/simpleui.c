#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 1000

void print(char *str) {
  while (*str != '\0') {
    printf("%c", *str);
    str++;
  }
  printf("\n");
}

int compareStrings(const char *temp1, const char *temp2) {
  while(*temp1 && *temp2) {
    if(*temp1 == *temp2) {
      temp1++;
      temp2++;
    } else {
      if (*temp1<*temp2) {
	return -1;
      } else {
	return 1;
      }
    }  }
  return 0;
}

void test() {
  printf("%d\n", space_char(' '));
  printf("%d\n", space_char('\t'));                            
  printf("%d\n", space_char('e'));
  printf("%d\n", space_char('6'));
  printf("here\n");
  
  printf("%d\n",non_space_char(' '));
  printf("%d\n", non_space_char('\t'));                            
  printf("%d\n", non_space_char('x'));
  printf("%d\n", non_space_char('2'));
  printf("here11\n");

  List* history = init_history();
  add_history(history, "yoooo");
  add_history(history, "yoooo2");

  printf("%s\n", get_history(history, 0));
  printf("%s\n", get_history(history, 1));
  printf("%s\n", get_history(history, 2));
  printf("%s\n", get_history(history, 3));
  print_history(history);
}
int main() {
  test();
  char str[MAX];
  int condition = 1;
  List* list = init_history();
  
  while(condition == 1) {
    printf("$ ");
    fgets(str, MAX, stdin);
    
    if (*str == '!') {
      int index = atoi(str+1);
      char *prv_str = get_history(list, index);
      if (prv_str !=NULL) {
	printf("Item #%d: ",index);
	printf(get_history(list, index));
      }
    }
    if(*str != '!'){
      add_history(list, str);
      char** tokens = tokenize(str);
      print_tokens(tokens);
      free_tokens(tokens);
    }
    if (*str == '0')
      condition = 0;
  }
  print_history(list);
  return 0;

}

