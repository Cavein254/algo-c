#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};

//in order transversal
void inordertransversal(struct node* root)
{
  if (root == NULL) return; //early return
  inordertransversal(root->left);
  printf("%d ->", root->item);
  inordertransversal(root->right);
}

void preordertransversal(struct node* root)
{
  if (root == NULL) return; //early return
  printf("%d -> ", root->item);
  preordertransversal(root->left);
  preordertransversal(root->right);
}

void postordertransversal(struct node* root)
{
  if (root == NULL) return;
  postordertransversal(root->left);
  postordertransversal(root->right);
  printf("%d -> ", root->item);
}


//create a new node
struct node* createnode (int value)
{
  struct node* newnode = malloc(sizeof(struct node));
  newnode->item = value;
  newnode->left = NULL;
  newnode->right = NULL;

return newnode;
}

//insert on the left of the node
struct node* insertleft(struct node* root, int value)
{
  root->left = createnode(value);
  return root->left;
}

struct node* insertright(struct node* root, int value)
{
  root->right = createnode(value);
  return root->right;
}

int main()
{
  struct node* root = createnode(1);
  insertleft(root, 12);
  insertright(root,9);

  insertleft(root->left, 5);
  insertright(root->right,6);

  printf("Inorder transversal \n");
  inordertransversal(root);

  printf("\n preorder transversal\n");
  preordertransversal(root);

  printf("\n postorder transversal \n");
  postordertransversal(root);
  
}
