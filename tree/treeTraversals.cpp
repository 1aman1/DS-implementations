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

void preOrder( tNode* pRoot ){
  if( pRoot ){
    cout << pRoot->data << " ";
    preOrder( pRoot->left );
    preOrder( pRoot->right );
  }
}

void inOrder(tNode* pRoot ){
  if( pRoot ){
    inOrder( pRoot->left );
    cout << pRoot->data <<" ";
    inOrder( pRoot->right);
  }
}

void postOrder( tNode* pRoot ){
  if( pRoot ){
    postOrder( pRoot->left );
    postOrder( pRoot->right );
    cout << pRoot->data <<" ";
  }
}

void iterativePreOrder( tNode* pRoot ){
  stack<tNode*> S;
  tNode* temp = pRoot;
  while(9){
    while( temp ){
      cout << temp->data << " ";
      S.push( temp );
      temp = temp->left;
    }
    if( S.empty() ) break;

    temp = S.top();
    S.pop();
    temp = temp->right;
  }
  while( !S.empty() ) S.pop();
}

void iterativeInOrder(tNode* pRoot ){
  stack<tNode*> S;
  tNode* temp = pRoot;
  while(9){
    while( temp ){
      S.push( temp );
      temp = temp->left;
    }
    if( S.empty() )
      break;
    temp = S.top();
    S.pop();
    cout << temp->data << " ";
    temp = temp->right;
  }
  while(!S.empty())  S.pop();
}

void iterativePostOrder(tNode* pRoot ){
  stack<tNode*> S;
  tNode* prev = NULL;
  do{
    while( pRoot ){
      S.push( pRoot );
      pRoot = pRoot->left;
    }

    while( pRoot == NULL && !S.empty() ){
      pRoot = S.top();
      if(pRoot->right == NULL || pRoot->right == prev ){
        cout << pRoot->data << " ";
        S.pop();
        prev = pRoot;
        pRoot = NULL;
      }
      else
        pRoot = pRoot->right;
    }
  }while( !S.empty() );
}

void levelOrder( tNode* pRoot ){
  queue<tNode*> Q;
  tNode* temp = NULL;
  Q.push( pRoot );
  while( !Q.empty() ){
    temp = Q.front(), Q.pop();

    cout << temp->data << " ";

    if( temp->left )
      Q.push( temp->left );
    if( temp->right )
      Q.push( temp->right );
  }
  while( !Q.empty() ) Q.pop();
  cout << endl;
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

  cout << "PREORDER  recursive: ";
  preOrder( root );
  cout << "\titerative: ";
  iterativePreOrder(root );

  cout << "\n INORDER  recursive: ";
  inOrder( root );
  cout << "\titerative: ";
  iterativeInOrder(root);

  cout << "\nPOSTORDER recursive: ";
  postOrder( root );
  cout << "\titerative: ";
  iterativePostOrder( root );

  cout << endl << "levelOrder: ";
  levelOrder( root );
  return 0;
}
