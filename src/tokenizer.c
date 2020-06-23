#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#define true 1
#define false 0

/* Returns true (non-zero if c is a whitespace char: ' ' or '\t'. */
int space_char(char c) {
  if (c==' ' || c =='\t') {
    return true;
  } else {
    return false;
  }
}

/* Returns true (non-zero) if c is a non-whitespace char: not ' ' or '\t' */
int non_space_char(char c) {
  if (c != ' ' && c != '\t') {
    return true;
  } else {
    return false;
  }
}

char *word_start(char *str){
  while(!non_space_char(*str)) {
    str = str + 1;
  }
  return str;
  
}

char *word_terminator(char *word) {
  while (non_space_char((*word))) {
    word = word + 1;
  }
  return word;
}

int count_words(char* str) {
  int OUT = 0;
  int IN = 1;
  int state = OUT;
  int count = 0; //count words to return

  while(*str) {
    if (*str == ' ' || *str == '\n' || *str == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      count++;
    }
    str++;
  }
  return count;
}

char *copy_str(char *inStr, short len) {
  char* helper = inStr;
  char* copyStr =  NULL;

  //allocate extra memory for '\0' at the end of the string
  copyStr = (char*) malloc(sizeof(char) * (len + 1));

  //add '\0' at the end of the string
  copyStr[len] = '\0';

  int index = 0;
  while(*helper != '\0') {
    copyStr[index++] = *helper++;
  }
  return copyStr;
}

char** tokenize(char* str) {
  int size = count_words(str);
  char **tokens;
  tokens =  (char**) malloc((size+1) * sizeof(char*));

  char* start = str;
  char* end = word_terminator(str);
  int i;
  for (i = 0; i < size; i++) {
    if (i > 0) {
      start = word_start(end);
      end = word_terminator(start);
    }

    int size2 =  end - start;
    tokens[i] = malloc(size2 * sizeof(char));
    for (int j = 0; j < size2; j++) {
      tokens[i][j] = start[j];
    }
  }
  tokens[i] = '\0';
  return tokens;
}

void print_tokens(char **tokens) {
  int i = 0;
  while(tokens[i] != NULL) {
    printf("%s\n", tokens[i]);
    i++;
  }
}

void free_tokens(char **tokens) {
  int i = 0;
  while(tokens[i]) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
