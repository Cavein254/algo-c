#include <stdio.h>
#include <stdlib.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */

struct binary_tree_s
{
  int n;
  struct binary_tree_s *parent;
  struct binary_tree_s *left;
  struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s av1_t;
typedef struct binary_tree_s heap_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
  {
    binary_tree_s *new_binary_tree = malloc(sizeof(binary_tree_s));
    new_binary_tree->left = NULL;
    new_binary_tree->right = NULL;
    new_binary_tree->n = value;

    return new_binary_tree;

  }
