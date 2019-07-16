#include<iostream>
using namespace std;

struct S_Node {
	int data;
  S_Node* next;

  S_Node(int x):data(x), next(NULL)
  {}
};

class stack {
  private:
    S_Node* top;
    size_t S_size;

  public:
    stack():top(NULL), S_size(0)
  {}

    void push( int );
    int pop();
    void peek();
    void menu();
};

void stack::push(int value) {
  S_Node* newNode = new S_Node(value);
  if(top == NULL) {
    top = newNode;
  }
	else {
    newNode->next = top;
    top = newNode;
  }
  ++S_size;
}

int stack::pop() {
  if(top == NULL) {
    return 0;
  }

  else {
    int copy = top->data;
    top = top->next;
   --S_size;
    return copy;
  }
}

void stack::peek() {
  if( S_size < 1 )
    cout << "stack empty\n";  
  else
    cout << "top : " << top->data << endl;
}

void stack::menu() {
	cout << "#-------LINKED LIST STACK IMPLEMENTATION-------#\n";
  int more = 1;
  int choice = 0;
  while(more) {
    cout << "\npress 0 for EXIT"
      <<"\n 1 push an element"
      <<"\n 2 pop an element"
      <<"\n 3 peek"
      <<"\n 4 to check size\n\t";

    cin >> choice;
    cout << endl;
    switch(choice) {
			case 0: {
                more = choice;
              }
              break;
      case 1: {
                cout << "\npush value : ";
                int value;
                cin >> value;
                push(value);
              }
              break;
      case 2: {
                cout << "Element Popped : " << pop() << endl;
              }
              break;
      case 3: {
                peek();
              }
              break;
      case 4: {
                cout << "\nsize : " << S_size << endl;
              }
              break;
      default: {
                 cout << "wrong choice\n";
               }
              break;
    }
  }
};

int main() {	
  stack runstack;
  runstack.menu();
  return 0;
}
