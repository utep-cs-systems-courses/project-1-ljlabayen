#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 1000

void test() {
  printf("Running tests...\n");
  printf("space_char test:\n");
  printf("%d\n", space_char(' '));
  printf("%d\n", space_char('\t'));                            
  printf("%d\n", space_char('e'));
  printf("%d\n", space_char('6'));

  printf("\nnon_space_char test:\n");
  printf("%d\n",non_space_char(' '));
  printf("%d\n", non_space_char('\t'));                            
  printf("%d\n", non_space_char('x'));
  printf("%d\n", non_space_char('2'));

  char t[]="dog has fleas";
  printf("\nword count test:\n");
  printf("%d\n", count_words(t));

  printf("\nhistory tests:\n");
  List* history = init_history();
  add_history(history, "the quick brown");
  add_history(history, "lazy dog");
  add_history(history, "computer science");
  printf("%s\n", get_history(history, 1));
  printf("%s\n", get_history(history, 2));
  printf("%s\n", get_history(history, 3));
  printf("\nprint history test:\n");
  print_history(history);
  
}

int main() {
  test();
  char str[MAX];
  int condition = 1;
  List *history = init_history();

  printf("\nHello! Enter string to be tokenized.\n");
  printf("Enter ! followed by the id to get history.\n");
  printf("0 to exit and print history then dealloacate\n");
  
  while(condition == 1) {
    printf("$ ");
    fgets(str, MAX, stdin);
    if (*str == '!') {
      int index = atoi(str+1);
      char *prv_str = get_history(history, index);
      if (prv_str != NULL) {
	printf("Item #%d: ",index);
	printf(get_history(history, index));
      }
    }
    if(*str != '!') { 
      char** tokens = tokenize(str);
      printf("Your tokenized string:\n");
      print_tokens(tokens); // print tokenized string
      add_history(history, str); // add string to history
      free_tokens(tokens); // free tokens
      // print_history(history);
    }
     if (*str == '0')
       condition = 0; 
  }
  print_history(history);
  free_history(history);
  return 0;

}
