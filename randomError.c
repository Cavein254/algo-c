#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
  srand(time(NULL) * getpid());
  
  int rand_val = rand();
  int pid = getpid();
  printf("Process id is: %d and the seed is %d\n", pid, rand_val);

  return 0;
}
