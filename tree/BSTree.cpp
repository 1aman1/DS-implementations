/*
 * BINARY SEARCH TREE IMPLEMENTATION IN CPP
 * */
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct T_Node {
  int data;
  T_Node *left, *right;

  T_Node(int x):data(x), left(nullptr), right(nullptr)      
  {}
  ~T_Node()
  {}
};

class tree {
private:
  //--ROOT--//
  struct T_Node* root;

public:
  tree():root(nullptr)
  {}

  void begin_menu();
	void insert(int );
  void search(int );
  void Delete(int );
  T_Node* findmin(T_Node* root);

  void display();
  void in_order  ( T_Node* );
  void pre_order ( T_Node* );
  void post_order( T_Node* );
  void breadth_first_search( T_Node* );
	void depth_first_search  ( T_Node* );

private:
  //suffic P introduced for not confusing with alias, but public, member 
  T_Node* searchP(T_Node* root, int item);
  T_Node* insertP(T_Node* root, int element);
  T_Node* DeleteP(T_Node* root, int data);
};

void tree::insert(int item) {
  if(!root) {
    root = new T_Node(item); 
    cout<< item << "-inserted" << endl;
    return;
  }

	if(item < root->data) {
		root->left = insertP(root->left, item);
	}
	else if(item > root->data) {
		root->right = insertP(root->right, item);
	}
	else {
		cout << "Already inserted\n";
	}
}

T_Node* tree::insertP(T_Node* root, int item) {													
	if(!root) {
		root = new T_Node(item); 
		return root;
	}

	if(item < root->data) {
		root->left = insertP(root->left, item);
		return root;
	}
	else if(item > root->data) {
		root->right = insertP(root->right, item);
		return root;
	}
	else {
		cout << "Already inserted\n";
	}
}

void tree::search(int element) {
  T_Node* copy = searchP(root, element);
  cout << "STATUS : search ";
  if( copy == nullptr || copy->data != element )
    cout << "unsuccessful : element not found\n";
  else 
    cout << "successful : element found\n\n";
}

T_Node* tree::searchP(struct T_Node* pRoot, int item) {						
  if(item == pRoot->data) {
		return pRoot;
	}
	else if(item < pRoot->data && pRoot->left) {
		return searchP(pRoot->left, item);
	}
	else if(item > pRoot->data && pRoot->right) {
		return searchP(pRoot->right, item);
	}
  else 
    return nullptr;
}

void tree::Delete( int element ) {
  //to avoid miscarried deletion, first check if the element is present
  T_Node* check = searchP(root, element);
  cout << "STATUS : Deletion ";
  if( check == nullptr || check->data != element ) 
    //element not present, must abort 
    cout << "unsuccessful : either element was not inserted or already deleted";
  else {
    DeleteP( root, element );
    cout << "successful : deleted " << element;
  }
  cout << endl;
}

T_Node* tree::DeleteP(T_Node* root, int data) {
	if(root == nullptr) 
		return root;
	else if(data < root->data)
		root->left = DeleteP(root->left, data);
	else if(data > root->data)
		root->right = DeleteP(root->right, data);
	else {
		if(root->left == nullptr && root->right == nullptr) {			
			delete root;
			root = nullptr;
		}
		else if(root->right == nullptr) {
			T_Node* temp = root;
			root = root->left;
			delete temp;
		}
		else if(root->left == nullptr) {
			T_Node* temp = root;
			root = root->right;
			delete temp;
		}
		else {
			T_Node* temp = findmin(root->right);
			root->data = temp->data;
			root->right = DeleteP(root->right, temp->data);
		}
	}
	return root;
}

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
				cout<<"\nThe Inorder structure is\n";
				in_order(root);
				cout<<endl;
			}
			break;
		case 2: {
				cout<<"\nThe pre_order structure is\n";
				pre_order(root);
				cout<<endl;
			}	
			break;
		case 3: {
				cout<<"\nThe post_order structure is\n";
				post_order(root);
				cout<<endl;
			}
			break;
		case 4: {
				cout<<"The breadth first search structure is \n";
				breadth_first_search(root);
				cout<<endl;
			}
			break;
		case 5: {
				cout<<"The depth first search structure is \n";
				depth_first_search(root);
				cout<<endl;
			}
			break;
		default: {
				cout<<"invalid input\n";
				cout<<endl;
			}
			break;
	}
}

T_Node* tree::findmin(T_Node* root) {
	if(root == nullptr) {
		cerr<<"_TREE EMPTY_";
		cout<<endl;
		return nullptr;
	}
	T_Node* curr = root;

	while(curr->left != nullptr) {
		curr = curr->left;
	}
	
	return curr;
}

/*---------traversals--------*/
void tree::in_order(T_Node* pRoot) {
	if(!pRoot) {
		return ;
	}

	in_order(pRoot->left);

	cout<<pRoot->data<<"\t";
	
	in_order(pRoot->right);
}

void tree::pre_order(T_Node* pRoot) {	
	if(!pRoot) {
		return ;
	}

	cout<<pRoot->data<<"\t";
	
	pre_order(pRoot->left);
	pre_order(pRoot->right);
}

void tree::post_order(T_Node* pRoot) {
	if(!pRoot) {
		return ;
	}

	post_order(pRoot->left);
	post_order(pRoot->right);

	cout<<pRoot->data<<"\t";
}

void tree::breadth_first_search(T_Node* pRoot) {
	if(pRoot == nullptr) {
		cerr<<"TREE_empty\n";
		return;
	}

	queue<T_Node*> MyQ;
	MyQ.push(pRoot);
	while(MyQ.size()) {
		T_Node* tmp = MyQ.front();
		MyQ.pop();
		cout<<tmp->data<<"\t";
		if(tmp->left != nullptr)
			MyQ.push(tmp->left);
		if(tmp->right != nullptr)
			MyQ.push(tmp->right);
	}
}

void tree::depth_first_search(T_Node* pRoot) {
	if(pRoot == nullptr) {
		cerr<<"TREE_empty\n";
		return;
	}

	stack<T_Node*> MyST;
	MyST.push(pRoot);
	while(MyST.size()) {
		T_Node* tmp = MyST.top();
		MyST.pop();
		cout<<tmp->data<<"\t";
		if(tmp->right != nullptr)
			MyST.push(tmp->right);
		if(tmp->left != nullptr)
			MyST.push(tmp->left);
	}
}

//-------------------------------------------------------------------------------------//
int main() {
	tree startrun;
	startrun.begin_menu();
	return 0;
}
