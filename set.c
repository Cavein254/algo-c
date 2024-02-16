#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int *members;
  int length;
}Set;

Set* init();
bool isEmpty(Set *set);
void insert(Set *set, int member);
void print_set(Set *set);
Set *set_union(Set *setA, Set *setB);
int main()
{
  Set *setA = init();
  
  if(isEmpty(setA)) printf("setA is empty\n");
  else printf("setA is not empty\n");

  insert(setA, 5);
  insert(setA, 6);
  insert(setA, 7);
  insert(setA, 7);

  Set *setB = init();
  insert(setB, 7);
  insert(setB, 6);
  insert(setB, 5);
  insert(setB, 9);
  insert(setB, 11);
  Set *setC = set_union(setA, setB);
  print_set(setC);
  
  return 0;
}

Set* init()
{
  Set *new_set = malloc(sizeof(Set));
  new_set->length = 0;
  new_set->members = malloc(sizeof(int));
  return new_set;
}

bool isEmpty(Set *set)
{
  return set->length==0;
}

void insert(Set *set, int member)
{
  bool in_set = false;
  for (int i = 0; i < set->length; i++)
    if(set->members[i] == member)
      in_set = true;
  if(!in_set)
  {
    //increment the length and add
    set->members = realloc(set->members, sizeof(int) * (set->length + 1));
    set->members[set->length]=member;
    set->length = set->length + 1;
  }
}

void print_set(Set *set)
{
  for(int i = 0; i < set->length; i++)
  {
    if (i == (set->length -1))
      printf("%d", set->members[i]);
    else
      printf("%d, ", set->members[i]);
  }
  printf("\n");
}

Set *set_union(Set *setA, Set *setB)
{
  Set *new = init();
  for (int i = 0; i < setA->length; i++)
    insert(new, setA->members[i]);
  for (int i = 0; i < setB->length; i++)
    insert(new, setB->members[i]);
  
  return new;
}
