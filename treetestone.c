#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node* left;
  struct node* right;
};

void transverseleft(struct node* root)
  {
    printf("\n\n\n");
    if(root ==NULL) return;
    printf("<--- %d ", root->value);
    transverseleft(root->left);
  }

void transverseright(struct node* root)
  {

    printf("\n\n\n");
    if(root ==NULL) return;
    printf("\n ---> %d", root->value);
    transverseright(root->right);
  }

struct node* createnode(int value)
  {
    struct node* newnode = malloc(sizeof(struct node));
    newnode->value = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
  }

struct node* add_left(struct node* root, int value)
  {
    root->left = createnode(value);
    return root-> left;
  }

struct node* add_right(struct node* root, int value)
  {
    root->right = createnode(value);
    return root->right;
  }


int main()
  {
    struct node* mynode = createnode(123);
    add_left(mynode, 2233);
    add_left(mynode, 1122);
    add_right(mynode, -22);
    add_right(mynode, 10);
    add_left(mynode, 99);

    transverseright(mynode);
    transverseleft(mynode);
  }
