#include <stdio.h>
#include <stdlib.h>
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
