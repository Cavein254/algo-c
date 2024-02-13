#include <stdio.h>
/**
Find the minimum number and the 
maximum number in the array
**/
int main(void)
{
  int myarray[] = {2,8,1,7,0,11,8,-1,-110};
  //create a loop
  int min = myarray[0];
  int max = myarray[0];

  int arr_size = sizeof(myarray)/ sizeof(myarray[0]);
  for (int i = 1; i < arr_size; i++)
  {
    if(myarray[i] < min) min = myarray[i];
    if(myarray[i] > max) max = myarray[i];
  }
  printf("The size of my array is %d \n", arr_size);
  printf("The largest int is %d and the smallest is %d \n",max, min);
  return 0;
}
