#include <stdio.h>
#define BUFF_SIZE 1024

int read_map(const char *filepath)
{
  FILE *file = fopen(filepath,"r");

  if(file == NULL)
  {
    perror("Error opening file");
    return 1;
  }

  char buff[BUFF_SIZE];

  while(fgets(buff, sizeof(buff), file) != NULL)
  {
    printf("%s", buff);
  }

  return 0;
}

int count_floors(char *str)
{
  int i = 0;
  int floor = 0;
  while(str[i] != '\0')
  {
    if(str[i] == '(') floor++;
    if(str[i] == ')') floor--;
    i++;
  }
  printf("Santa's last floor is: %d \n", floor);
  return 0; 
}

int main(void)
{
  char my_str[] = "(()) ()()";
  char my_str2[] = "((( and (()(()(";
  char my_str3[] = "()) and ))(";
  char my_str4[] = "))) and )())())";

  count_floors(my_str); // 0
  count_floors(my_str2); // 3
  count_floors(my_str3);// -1
  count_floors(my_str4); // -3

  read_map("2015-1.txt");
    return 0;
}
