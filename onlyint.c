#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define BUFFER_SIZE 4096
/**
scanf has problem detecting integers
as 'abc' '12.53'  
**/
bool parse_int(char *string, int *integer);
int main()
{
  int my_int;
  
  printf("Enter an interger: ");
  scanf("%d", &my_int);
  printf("\n you entered: %d \n", my_int);

  return 0;
}

bool parse_int(char *string, int *integer)
{
  int i = 0;
  while(isspace(string[i])) i++;
  
  int length = strlen(string);

  if (length == i) return false;

  char int_buff[BUFFER_SIZE];
  int int_chars = 0;
  if (string[i] == '-')
  {
    int_buff[int_chars] = '-';
    int_chars++;
    i++;
  } 
}
