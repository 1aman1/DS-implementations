#include<bits/stdc++.h>

using namespace std;

class tNode{
public:
  size_t data;
  tNode* left;
  tNode* right;
  tNode( int item ): data( item )
  {}
};

int height( tNode* pRoot ){
  int left , right;
  if( !pRoot )
    return 0;
  else{
    left = height( pRoot->left );
    right = height( pRoot->right );
    if( left > right )
      return 1+left;
    else
      return 1+right;
  }
}

int main(){

  tNode* root = new tNode(1);
  tNode* newNode1 = new tNode(2);
  tNode* newNode2 = new tNode(3);
  tNode* newNode3 = new tNode(4);
  tNode* newNode4 = new tNode(5);
  tNode* newNode5 = new tNode(6);
  tNode* newNode6 = new tNode(7);

  root->left = newNode1;
  root->right = newNode2 ;
  newNode1->left = newNode3;
  newNode1->right= newNode4;
  newNode2->left = newNode5;
  newNode2->right = newNode6;

  //  levelOrder( root );
  cout  << height( root ) << endl;
  return 0;
}
