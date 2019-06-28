/*   C++ program to Implement AVL Tree */
#include<iostream>
using namespace std;
 
struct AVL_Node {
  int data;
  struct AVL_Node *left;
  struct AVL_Node *right;

  AVL_Node(int x ):data(x), left(NULL), right(NULL)
  {}
};

/*----------------------------------------- Class Declaration */
class avlTree {
  private:

    AVL_Node* root;

    AVL_Node* insert( AVL_Node *, int );
    AVL_Node* Delete( AVL_Node *, int );
    AVL_Node* findmin( AVL_Node * );

    AVL_Node* balance( AVL_Node * );
    int diff( AVL_Node * );
    size_t height( AVL_Node * );
    AVL_Node *rr_rotation( AVL_Node * );
    AVL_Node *ll_rotation( AVL_Node * );
    AVL_Node *lr_rotation( AVL_Node * );
    AVL_Node *rl_rotation( AVL_Node * );
 
    void display( AVL_Node *, int );
    void inorder( AVL_Node *);
    void preorder( AVL_Node *);
    void postorder( AVL_Node *);

  public:
    avlTree() {
      root = NULL;
    }
    void beginmenu();
};

void avlTree::beginmenu() {
  int more = 1, choice, item;
  while (more) {
    cout << "\n---------------------\n"
      << "\nAVL Tree Implementation\n"
      << "\n---------------------\n"
      << "1.Insert Element into the tree\n"
      << "2.Display Balanced AVL Tree\n"
      << "3.InOrder traversal\n"
      << "4.PreOrder traversal\n"
      << "5.PostOrder traversal\n"
      << "6.To Delete an element\n"
      << "0.Exit\n"
      << "Enter your Choice: \n";
    cin >> choice;
    switch(choice) {
      case 1: {
                cout << "\nValue to be inserted: ";
                cin >> item;
                root = insert(root, item);
              }
              break;
      case 2: {
                if (root == NULL) {
                  cout << "\nTree is Empty" << endl;
                  break;
                }
                cout << "\nBalanced AVL Tree:" << endl;
                display(root, 1);
              }
              break;
      case 3: {
                cout << "\nInorder Traversal:" << endl;
                inorder(root);
                cout << endl;
              }
              break; 
      case 4: { 
                cout << "\nPreorder Traversal:" << endl;
                preorder(root);
                cout << endl;
              }
              break;
      case 5: {
                cout << "\nPostorder Traversal:" << endl;
                postorder(root);    
                cout << endl;
              }           
              break;
      case 6: {
                cout << "\nEnter value to be Deleted: ";
                cin >> item;
                root = Delete(root, item);
              }
              break;
      case 0:	{
                more = choice; 
              }            
              break;
      default:
              cout << "Wrong Choice" << endl;
    }
  }
}

/*--------------------------------------------- Insert Element into the tree */
AVL_Node *avlTree::insert(AVL_Node *pRoot, int value) {
  if (pRoot == NULL) {
    pRoot = new AVL_Node(value);
    return pRoot;
  }
  else if (value < pRoot->data) {
    pRoot->left = insert(pRoot->left, value);
    pRoot = balance (pRoot);
  }
  else if (value >= pRoot->data) {
    pRoot->right = insert(pRoot->right, value);
    pRoot = balance (pRoot);
  }
  return pRoot;
}


/* ---------------------------------------------Delete element from AVL tree */
AVL_Node* avlTree::Delete( AVL_Node* pRoot, int data) {
  if(pRoot == NULL) 
    return pRoot;
  else if(data < pRoot->data)
    pRoot->left = Delete(pRoot->left, data);
  else if(data > pRoot->data)
    pRoot->right = Delete(pRoot->right, data);
  else {
    if(pRoot->left == NULL && pRoot->right == NULL) {			
      delete pRoot;
      pRoot = NULL;
    }
    else if(pRoot->right == NULL) {
			AVL_Node* temp = pRoot;
			pRoot = pRoot->left;
			delete temp;
		}
		else if(pRoot->left == NULL) {
			AVL_Node* temp = pRoot;
			pRoot = pRoot->right;
			delete temp;
		}
		else {
			AVL_Node* temp = findmin(pRoot->right);
			pRoot->data = temp->data;
			pRoot->right = Delete(pRoot->right, temp->data);
		}
	}
	root = balance(root);
	return pRoot;
}

AVL_Node* avlTree::findmin(AVL_Node* pRoot) {
  if(pRoot == NULL) {
    cerr << "_TREE EMPTY_";
    return NULL;
  }
  AVL_Node* curr = pRoot;

  while(curr->left != NULL) 
    curr = curr->left;

  return curr;
}

/*------------------------------------------ Height of AVL Tree */
size_t avlTree::height(AVL_Node *parent) {
  if (parent != NULL) {
    size_t l_height = ((parent->left == NULL)  ? 0 : height(parent->left));
    size_t r_height = ((parent->right == NULL) ? 0 : height(parent->right));

    return ( ( l_height > r_height ) ? l_height +1 : r_height +1 );
  }
  else 
    return 0;
}

/*--------------------------------------------- Height Difference  */
int avlTree::diff(AVL_Node *temp) {
  int l_height = height (temp->left);
  int r_height = height (temp->right);

  return  (l_height - r_height);
}

/*---------------------------------------------- Balancing AVL Tree */
AVL_Node *avlTree::balance(AVL_Node *parentRoot) {
  int bal_factor = diff (parentRoot);
  if (bal_factor > 1) {
    if (diff (parentRoot->left) > 0)
      parentRoot = ll_rotation (parentRoot);
    else
      parentRoot = lr_rotation (parentRoot);
  }
  else if (bal_factor < -1) {
    if (diff (parentRoot->right) > 0)
      parentRoot = rl_rotation (parentRoot);
    else
      parentRoot = rr_rotation (parentRoot);
  }
  return parentRoot;
}

/*--------------------------------------------- Display AVL Tree */
void avlTree::display(AVL_Node *ptr, int level) {
  int i;
  if (ptr!=NULL) {
    display(ptr->right, level + 1);
    printf("\n");
    if (ptr == root)
      cout << "Root -> ";
    for (i = 0; i < level && ptr != root; i++)
      cout << "        ";
    cout << ptr->data;
    display(ptr->left, level + 1);
  }
}
/*--------------------------------------------Traversals of AVL Tree */
void avlTree::inorder(AVL_Node *pRoot) {
  if (pRoot == NULL)
        return;
  inorder (pRoot->left);
  cout << pRoot->data << "  ";
  inorder (pRoot->right);
}

void avlTree::preorder(AVL_Node *pRoot) {
  if (pRoot == NULL)
    return;
  cout << pRoot->data << "  ";
  preorder (pRoot->left);
  preorder (pRoot->right);
}
 
void avlTree::postorder(AVL_Node *pRoot) {
  if (pRoot == NULL)
    return;
  postorder ( pRoot->left );
  postorder ( pRoot ->right );
  cout << pRoot->data << "  ";
}

/*----------------------------------------------- Right- Right Rotation */
AVL_Node *avlTree::rr_rotation(AVL_Node *parent) {
  AVL_Node* temp = parent->right;
  parent->right = temp->left;
  temp->left = parent;
  return temp;
}

/*----------------------------------------------- Left- Left Rotation */
AVL_Node *avlTree::ll_rotation(AVL_Node *parent) {
  AVL_Node *temp = parent->left;
  parent->left = temp->right;
  temp->right = parent;
  return temp;
}

/*---------------------------------------------- Left - Right Rotation */
AVL_Node *avlTree::lr_rotation(AVL_Node *parent) {
  AVL_Node *temp = parent->left;
  parent->left = rr_rotation (temp);
  return ll_rotation (parent);
}

/*------------------------------------------- Right- Left Rotation */
AVL_Node *avlTree::rl_rotation(AVL_Node *parent) {
  AVL_Node *temp = parent->right;
  parent->right = ll_rotation (temp);
  return rr_rotation (parent);
}

int main() {
  avlTree run;
  run.beginmenu();
  return 0;
}
