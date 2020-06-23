#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main() {
  int condition = 1;
 
  while(condition == 1) {
    printf("$ ");
    fgets(word, 1000, stdin);
  }
  return 0;
}
