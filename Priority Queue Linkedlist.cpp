#include<iostream>
using namespace std;

struct Node {
  int value;
  int priority;
  Node* next;

  Node(int _value, int _prior):value(_value), priority(_prior),  next(NULL)
  {}
  Node():next(NULL)
  {}
};

class priorityQueue {
  private:
    Node* head;
    size_t _size;

  public:
    priorityQueue():head(NULL), _size(0)
  {}
    bool insert();
    bool pop();
    void Size();
    void print();
    void menu();
};

bool priorityQueue::insert() {
  int value, priority;
  Node* traverse = new Node();
  traverse = head;
  cout << "\ninput value, then priority\n-->";
  cin >> value >> priority;
  Node* newNode = new Node(value, priority);
  if( head == NULL ) {
    newNode->next = head;
    head = newNode;
	}
  else if( head->next == NULL ) {
    if( newNode->priority < head->priority ) {
      newNode->next = head;
      head = newNode;
    }
    else {
      head->next = newNode;
    }
  }
  else {
    while( newNode->priority > traverse->priority && traverse ) {
      traverse = traverse->next;
    }
    newNode->next = traverse->next;
    traverse->next = newNode;
  }
  return true;
}

bool priorityQueue::pop() {
  if(head == NULL) {
    cerr << "__QUEUE-EMPTY__\n";
    return false;
  }

	Node* firstNode = head;
	head = head->next;
	delete firstNode;
	cout << "\tDELETED\n";
	return true;
}

void priorityQueue::print() {
	Node* traverse = head;
	if(head == NULL) {
		cout << "__EMPTY-LIST__";
		return;
	}
  else {
    cout << "[  LIST  ]\n";
    while(traverse != NULL) {
      cout << "priority level -> " << traverse->priority <<" :   "
        << traverse->value << "\n";
      traverse = traverse->next;
    }
  }
}

void priorityQueue::menu() {
  int more = 1;
  int choice = 0;
  while(more) {
    cout << "\n0 for exit"
      << "\n1 to push an element"
      << "\n2 for popping an element"
      << "\n3 for printing the list\n-->";
    cin >> choice;
    cout << "\n";
    switch(choice) {
      case 0: {
                more = choice;
              }
              break;
      case 1: {
                insert();
              }
              break;
      case 2: {
                pop();
              }
              break;
      case 3:  {
                 print();
               }
               break;
      case 4: {
                cout<<_size;
              }
              break;
    }
  }
}

void priorityQueue::Size() {
  cout << "\nsize is" << _size;
}

int main() {
	priorityQueue run_myqueue;
	run_myqueue.menu();
	return 0;
}
