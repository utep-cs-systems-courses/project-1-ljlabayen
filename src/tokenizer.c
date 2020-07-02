#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#define true 1
#define false 0

int space_char(char c) {
  if (c==' ' || c =='\t') {
    return true;
  } else {
    return false;
  }
}

int non_space_char(char c) {
  if (c != ' ' && c != '\t') {
    return true;
  } else {
    return false;
  }
}

char *word_start(char *str){
  while(!non_space_char(*str)) { // use non_space_char to iterate
    str = str + 1; // increment to next character
  }
  return str;
  
}

char *word_terminator(char *word) {
  while (non_space_char((*word))) { // use non_space_char to iterate
    word = word + 1; //increment to next character
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
    } else if (state == OUT) { // if state is OUT then we have seen 1 word
      state = IN;
      count++; // increment word count
    }
    str++; //increment pointer
  }
  return count;
}

char *copy_str(char *inStr, short len) {
  char *copyStr;

  //allocate extra memory for '\0' at the end of the string
  copyStr = (char*) malloc(sizeof(char) * (len + 1));

  int i;
  for(i=0; i < len; i++) 
    copyStr[i] = inStr[i]; // copy each character

  copyStr[i]='\0'; // set last charcter to '\0'
    
  return copyStr;
}

char** tokenize(char* str) {
  int size = count_words(str);
  char **tokens;
  tokens =  (char**) malloc((size+1) * sizeof(char*)); // allocating memory 

  char* start = str;
  char* end = word_terminator(str); // use word_terminator to word end
  int i;
  for (i = 0; i < size; i++) {
    if (i > 0) {
      start = word_start(end);
      end = word_terminator(start);
    }

    int size2 =  end - start;
    tokens[i] = malloc(size2 * sizeof(char)); // allocate for size of the word
    for (int j = 0; j < size2; j++) {
      tokens[i][j] = start[j]; // insert to tokens
    }
  }
  tokens[i] = '\0';
  return tokens;
}

void print_tokens(char **tokens) {
  // iterate 2D array using double for loop to print
  for(int i = 0; tokens[i] != NULL; i++) {
    for(int j = 0; tokens[i][j] != '\0'; j++) {
      printf("%c", tokens[i][j]);
    }
    printf("\n");
  }
}
    				  
void free_tokens(char **tokens) {
  int i = 0;
  while(tokens[i]) { // loop to iterate through all tokens
    free(tokens[i]); // each token is freed
    i++; // increment for next token
  }
  free(tokens); //free double pointer
}
