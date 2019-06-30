#include<iostream>
using namespace std;
//strcuture for the tree nodes
struct node {
  int data;
  node* left;
  node* right;
};

//node for tree
struct node* newNode(int a) {
  struct node* newNode = new node;
  newNode->data = a;
  newNode->left = newNode->right = NULL;
  return newNode;
}

bool areIdentical(struct node * A, struct node *B) {
  /* base cases */
  if (A == NULL && B == NULL)
    return true;

  if (A == NULL || B == NULL)
    return false;

  /* Check if the value stored in current node is same,
     and do the same for left and right subtrees, in subsequence */
  return (A->data == B->data	&&	areIdentical(A->left, B->left)	&  areIdentical(A->right, B->right) );
}
 
bool isSubtree(struct node* A, struct node* B) {
  //check if any of tree is empty -->ABORT
  if( A == NULL || B == NULL )
    return false;
  //check if ROOTs are identical
  if(areIdentical(A, B))
    return true;
  /*here the second tree would be the subtree,so we will pass the second tree as it is,
    inspite of the first one whose left and right nodes would be checked as per logic*/
  return isSubtree(A->left, B) || isSubtree(A->right, B);
}

int main() {
  // TREE 1
  /* Constructed this following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
  struct node *T        = newNode(26);
  T->right              = newNode(3);
  T->right->right       = newNode(3);
  T->left               = newNode(10);
  T->left->left         = newNode(4);
  T->left->left->right  = newNode(30);
  T->left->right        = newNode(6);

  // TREE 2
  /* Construct the following tree
          10
        /    \
       4      6
        \
         30
    */
  struct node *S    = newNode(10);
  S->right          = newNode(6);
  S->left           = newNode(4);
  S->left->right    = newNode(30);

  if (isSubtree(T, S))
    printf("Tree 2 is subtree of Tree 1\n");
  else
    printf("Tree 2 is not a subtree of Tree 1\n");

  //    system("pause");
  return 0;
}
