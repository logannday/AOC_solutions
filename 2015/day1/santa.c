#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) 
{
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "null fp\n");
  }
  int c;
  int stair_counter = 0;
  int level = 0;
  int index = 0;
  int return_index = 0;
  bool first_time = true;
  while((c = getc(fp)) != EOF) {
    // printf("%c", c);
    if(c == '(') {
      stair_counter++;
      index++;
    } else if (c == ')') {
      stair_counter--;
      index++;
    }

    if(stair_counter < 0 && first_time) {
      return_index = index;
      first_time = false;
    }

  }
  printf("stairs: %d, return index: %d", stair_counter, return_index);
}
