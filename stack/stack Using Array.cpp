#include<iostream>
using namespace std;
#define Len 20

class stack {
  private:

    int stack_top;
    int Stack_arr[Len];
    size_t size;

  public:
    stack();

    void push( int );
    int pop();
    int peek();
    void display();
    void menu();
};

void stack::push(int value) {
	Stack_arr[++stack_top] = value;
	++size;
}

int stack::pop() {
	--size;
	return Stack_arr[stack_top--];
}
	
int stack::peek() {
	return Stack_arr[stack_top];
}

void stack::menu() {
  cout << "#------beginner level stack implementation------#";
	int more = 1;
	int choice = 0;
	while(more) {
		cout<<"\n\npress 0 for EXIT"
			<<"\n 1 push an element into the stack"
			<<"\n 2 pop an element"
			<<"\n 3 peek"
			<<"\n 4 check the size\n";
				
		cin >> choice;
		switch(choice) {
			case 0: {
                more = choice;
              }
              break;
      case 1: {
                int value;
                cout << "\nvalue to push :";
                cin >> value;
                push(value);
              }
              break;
      case 2: {
                cout << "Popped element : " << pop() << endl;
              }
              break;
      case 3: {
                cout << "\nTopmost element.." << peek() << endl;
              }
              break;
      case 4: {
                cout << "\nsize : " << size << endl;
              }
              break;
      default: {
                 cout << "wrong input\n";
               }
              break;
    }
  }
};

stack::stack() {
  stack_top = -1; // -1 signifies stack is empty
	size = 0;
}

//---------------------------------------------------------------
int main() {	
	stack runstack;
	runstack.menu();
  return 0;
}

