/*
 *BINARY SEARCH TREE IMPLEMENTATION IN CPP
 * */
#include<iostream>
#include<algorithm>

using namespace std;
//tree struct
struct t_node {
  int data;
  t_node* left;
  t_node* right;

  t_node(int x):data(x), left(NULL), right(NULL)      
  {}
  ~t_node()
  {}
};

//stack struct
struct S_Node {
	t_node* item;
  S_Node* next;

  S_Node(t_node* x):item(x), next(NULL)
  {}
};

class stack {
  private:
    S_Node* top;
    size_t S_Size;
  public:
    stack():S_Size(0), top(NULL)
  {}
    void push( t_node*);
    t_node* pop();		
    S_Node* peek();
    size_t size();
};

//queue struct
struct q_node { 
  t_node* data;
  q_node* next;

  q_node( t_node* x ):data(x), next(NULL)
  {}
};									

class queue {
  private:
    q_node* front;
    q_node* rear;

  public:
    queue():front(NULL), rear(NULL), size(0)
  {}
    int size ;
    void menu();
    void enqueue( t_node* );
    t_node* dequeue();
    void size_func();
    void isempty();
};

void queue::enqueue( t_node* p_Root ) {
  q_node* newNode = new q_node( p_Root );
  if(front == NULL) {
    size = 0;
    front = rear = newNode;
    newNode->next = NULL;
    ++size;
  }
  else {
    rear->next = newNode;
    newNode->next = NULL;
    rear = newNode;
    ++size;
  }
}

t_node* queue::dequeue() {		
  if(front  == NULL) {
    cout << "____QUEUE_EMPTY____\n";
    return NULL ;
  }
  else {
    q_node* traverse = front;
    t_node* copy(front->data);
    front = front->next;
    delete traverse;
    //    cout << "_";
    --size;
    return copy;
  }
}	

void queue::size_func() {
  cout << "\nsize is:" << size << "\n";
}

void queue::isempty() {
  if( size == 0 )
    cout << "QUEUE_empty\n";
  else
    cout << "QUEUE_not_empty,size is " << "\n";
}

typedef enum {
  not_found = 0,
  found_in_left_subtree = 1,
  found_in_rite_subtree = 2
} enumInOrderNode;

class tree {
  public:
    tree():root(NULL)
  {}
    void begin_menu();
    void insert(int element);
    void display();
    void in_order( t_node* );
    void pre_order( t_node* );
    void post_order( t_node* );
    void breadth_first_search();
    void depth_first_search();
    void Delete ( int );
    t_node* search( int );

  private:
    t_node* search( t_node* , int );
    t_node* insert( t_node* , int );
    t_node* Delete( t_node* , int );
    enumInOrderNode findInorderNodeInThisSubtree( t_node * , t_node * &);
    t_node* root;
};

void tree::begin_menu() {
  cout << "___BINARY_SEARCH_TREE___\n\n";
  int element, option, more = 1;
  while(more) {
    cout << "#---------#---------#---------#--------#"
      << "\n 1 for insert element(s)"
      << "\n 2 for searching an element"
      << "\n 3 for displaying"
			<< "\n 4 for deletion"
      << "\n0 to quit";
    cout << "\n\n->";

    cin >> option;
    switch(option) {
      case 0: {
                more = option;
              }
              break;
      case 1: {
                cout << "\ninsert element: ";
                cin >> element;
                insert(element);
              }
              break;
      case 2: {
                cout << "\nsearch element ";
                cin >> element;
                search(element);	
              }
              break;
      case 3: {
                display();
                cout << endl;
              }
              break;
      case 4: {
                cout << "\ndelete element: ";
                cin >> element;
                Delete(element);
              }
              break;
    }
  }
}

void tree::insert( int item ) {
  if(!root) {
    root = new t_node(item); 
    return;
  }

  if(item < root->data){
    root->left = insert(root->left, item);
  }
  else if(item > root->data){
    root->right = insert(root->right, item);
  }
  else {
    cout << "Already inserted\n";
  }
}

t_node* tree::insert(t_node* root, int item) {	
  if(!root) {
    root = new t_node(item); 
    return root;
  }

  if(item < root->data) {
    root->left = insert(root->left, item);
    return root;
  }
  else // ( item > root->data) {
    root->right = insert(root->right, item);
  return root;
	
}

t_node* tree::search( int element ) {
  if( element == root->data ) {
		cout << "element found\n";
    return root;	
  }
  else if(element > root->data) {
    if (nullptr == search(root->right ,element))
      cerr << "Not found\n";
  }
  else if (element < root->data) {
    if(nullptr == search(root->left, element))
      cerr << "Not found\n";
  }
}

t_node* tree::search(t_node* pRoot, int item) {						//under consideration
  if(item == pRoot->data) {
    cout << "element found\n";
    return pRoot;
  }
  else if(item < root->data && root->left) {
    return search(root->left ,item);
  }
  else if(item > root->data && root->right) {
    return search(root->right , item);
  }
  return pRoot;
}

void tree::Delete(int item) {
  if(!root) {
    cerr << "TREE_empty\n";
    return ;
  }

  root = Delete(root, item);
}

t_node* tree::Delete(t_node* pRoot, int item) {
  if(item == pRoot->data) {
    t_node* inorderNode = NULL;
    enumInOrderNode foundAt = findInorderNodeInThisSubtree(pRoot, inorderNode);
    if (not_found == foundAt) {
				delete pRoot;
        pRoot = NULL;
    }
    else {
      int tmp = pRoot->data;
      pRoot->data = inorderNode->data;
      inorderNode->data = tmp;

			if(found_in_left_subtree == foundAt) {
        pRoot->left = Delete(pRoot->left, item);
      }
			else {
        pRoot->right = Delete(pRoot->right, item);
      }
    }
  }
  else if(item < pRoot->data) {
    pRoot->left = Delete(pRoot->left, item);
  }
  else {
    pRoot->right = Delete(pRoot->right, item);
  }
  return pRoot;
}

enumInOrderNode tree::findInorderNodeInThisSubtree(t_node* pRoot, t_node* & inOrderNode) {
  if(pRoot->left == NULL && pRoot->right ==  NULL) {
    return not_found;
  }
  else if(pRoot->left != NULL) {
    inOrderNode = pRoot->left;
    while(inOrderNode->right != NULL) {
			inOrderNode = inOrderNode->right;
		}
    return found_in_left_subtree;
  }
  else {
    inOrderNode = pRoot->right;
		while(inOrderNode->left != NULL) {
      inOrderNode = inOrderNode->left;
    }
    return found_in_rite_subtree;
  }
}

void stack::push(t_node* item) {
  S_Node* Newnode = new S_Node(item);

  if(top == NULL) {
    top = Newnode;
  }
  else {
    Newnode->next = top;
    top = Newnode;
  }
  ++S_Size;
}

t_node* stack::pop() {
  if(top == NULL) 
    //cout<<"\n__STACK-EMPTY__\n";
    return NULL;	
  else {
    t_node* copy = top->item;
    top = top->next;
    --S_Size;
    return copy;
  }
}

S_Node* stack::peek() {
  return top;
}

size_t stack::size() {
  return S_Size;
}

void tree::display() {
  int choice ;
  cout << "\nfill in choice to print\n"
    << "\n1-In order"
    << "\t2-pre order"
    << "\t3-post order"
    << "\t4-breadth first"
    << "\t5-depth first\n";
  cin >> choice;

  switch(choice) {
    case 1: {
              cout << "\nThe Inorder structure is\n";
              in_order(root);
            }
            break;
    case 2: {
              cout << "\nThe pre_order structure is\n";
              pre_order(root);
            }	
            break;
    case 3: {
              cout << "\nThe post_order structure is\n";
              post_order(root);
            }
            break;
    case 4: {
              cout << "The breadth first search structure is \n";
              breadth_first_search();
            }
            break;
    case 5: {
              cout << "The depth first search structure is \n";
              depth_first_search();
            }
            break;
    default: {
               cout << "invalid input\n";
             }
             break;
  }
}
//PRINT section
void tree::in_order(t_node* pRoot) {
  if(!pRoot) {
    return ;
  }

  in_order(pRoot->left);

  cout << pRoot->data << "\t";

  in_order(pRoot->right);
}

void tree::pre_order(t_node* pRoot) {	
  if(!pRoot) {
    return ;
  }

  cout << pRoot->data << "\t";

  pre_order(pRoot->left);
  pre_order(pRoot->right);
}

void tree::post_order(t_node* pRoot) {
  if(!pRoot) {
    return ;
	}

  post_order(pRoot->left);
  post_order(pRoot->right);

	cout << pRoot->data << "\t";
}

void tree::breadth_first_search() {
  if(root == NULL) {
    cerr << "TREE_empty\n";
    return;
	}

  queue q_obj;
	q_obj.enqueue(root);
  while(q_obj.size != 0) {
    t_node* tmp = q_obj.dequeue();
		cout << tmp->data << "\t";
    if(tmp->left != NULL)
      q_obj.enqueue(tmp->left);
    if(tmp->right != NULL)
			q_obj.enqueue(tmp->right);
  }
}

void tree::depth_first_search() {
  if(root == NULL) {
    cerr << "TREE_empty\n";
		return;
  }
  stack s_obj;
  s_obj.push(root);

  while( s_obj.size() != 0 ) {
    t_node* tmp = s_obj.pop();
    cout << tmp->data << "\t";
    if(tmp->left != NULL)
      s_obj.push(tmp->left);
    if(tmp->right != NULL)
      s_obj.push(tmp->right);
	}
}

//---------------------------------------------
int main() {
  tree o;
  o.begin_menu();

  return 0;
}
