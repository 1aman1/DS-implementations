/*
this project demonstrates doubly linked list as a class
*/
#include<iostream>
using namespace std;

struct node {
  int value;
  node* next;
  node* prev;

  node(int _value):value(_value), next(NULL), prev(NULL)
	{}
};

class doublyLinkedList {
  private:
    node* head;
    size_t _size;

  public:
    doublyLinkedList():head(NULL), _size(0)		
  {}
    ~doublyLinkedList()		
    {
      /*cout<<__FUNCTION__<<endl;
        node* pre = NULL;
        node* post = head;
        while(NULL != post)
        {
        pre = post;
        post = post->next;
        cout<<"Deleting:"<<pre->value<<"\n";
        delete pre;
        }
        cout<<"List destructed\n:";*/	
    }

    void print();
    size_t size();
    void menu();

    bool addAtFront( int );
    bool addAtEnd( int );
    bool addAtindex( int, size_t );

    bool deleteAtFront();
    bool deleteAtEnd();
    bool deleteAtindex( size_t );
    bool deleteNodeWithValue( int );
};

void doublyLinkedList::print() {
  cout << "Elements are ";
  node* traverse = head;
  while(traverse != NULL) {
		cout << traverse->value << " : ";
    traverse = traverse->next;
  }
  cout << "\n";
}

size_t doublyLinkedList::size() {
  return _size;
}

bool doublyLinkedList::addAtFront(int newValue) {
  node* newNode = new node(newValue);
  if(head == NULL) {
    head = newNode;
  }		
  else {	
    newNode->next = head;
    head->prev = newNode;	
    head = newNode; 		
  }
  ++_size;
  return true;
}

bool doublyLinkedList::addAtindex(int newValue, size_t index) { 
  if( index == 1 )
    addAtFront( newValue );
  else if ( index >= _size )
    addAtEnd( newValue );
  else {
    unsigned int count = 1;
    node* traverse = head;
    node* preptr = NULL;
    while(count < index) {
      ++count;
      preptr = traverse;
      traverse = traverse->next;
    }

    node* newNode = new node(newValue);
    newNode->next = preptr->next;
    traverse->prev = newNode;
    newNode->prev = traverse->prev;
    preptr->next = newNode;

    ++_size;
  }
  return true;
}

bool doublyLinkedList::addAtEnd(int newValue) {
	node* newNode = new node(newValue);
	node* traverse = head;
	node* pre = NULL;
  while(traverse != NULL) {	
    pre = traverse;												 
		traverse = traverse->next;
	}	

	newNode->prev = pre;
	pre->next = newNode;
	++_size;
	
	return true;
}

bool doublyLinkedList::deleteAtFront() {
  if(head == NULL) {
    cerr << "list is empty\n";
    return false;
  }

  node* firstNode = head;
  head = firstNode->next;
  firstNode->next->prev = NULL;

  delete firstNode;
  --_size;
  cout << "deleted";
  return true;
}								
bool doublyLinkedList::deleteAtindex(size_t index) {
  if( index == 1 )
    deleteAtFront();
  else if ( index >= _size )
    deleteAtEnd();
  else {
    unsigned int count = 1;
    node* traverse = head;
    node* preptr = NULL;
    node* _remove = NULL;
    while(count < index) {
      ++count;
      preptr = traverse;
      traverse = traverse->next;
    }
    _remove = preptr->next;
    preptr->next = traverse->next;
    traverse->next->prev = traverse->prev;
    cout << "deleted";
    --_size;
    return true;
  }
}

bool doublyLinkedList::deleteAtEnd() {
  if(head == NULL) {
    cerr << "list is empty\n";
    return false;
  }
  
  node* to_lastNode = NULL;
  node* temp = head;
  while(temp != NULL) {	 
    to_lastNode = temp;												 
    temp = temp->next;
  }	
  temp = to_lastNode->prev;
  temp->next = NULL;
  delete to_lastNode;
  cout << "deleted";
  --_size;
  return true;
}

void doublyLinkedList::menu() {
	int more = 1, choice = 0;
	while( more ) {
    cout << "\n0 for Exit\n"
      <<" 1 add at front\n"
      <<" 2 add at end\n"
      <<" 3 add at @ index\n"
      <<" 4 Print list\n"
      <<" 5 print size\n"
      <<" 7 Delete first element\n"
      <<" 8 Delete at @ index\n"
      <<" 9 Delete last element\n-->";
    
    cin >> choice;
    cout << "\n\n";
    switch(choice) {
      case 0: {
                more = choice;
              }
              break;
      case 1: {
                int value;
                cout << "Enter value : ";
                cin >> value;
                addAtFront(value);
              }
              break;
      case 2: {
                int value;
                cout << "Enter value : ";
                cin >> value;
                addAtEnd(value);
              }
              break;
      case 3: {
                int newValue, index;
                cout << "enter the value and index\n";
                cin >> newValue >> index;
                addAtindex(newValue, index);
              }
              break;
      case 4: {
                cout << "-->";
                print();
              }
              break;
      case 5:
              {				
                cout << "size is " << size() << "\n";
              }
              break;
      case 7: {
                deleteAtFront();
              }
              break;
      case 9: {
                deleteAtEnd();
              }
              break;
      case 8: {
                unsigned int index;
                cout << "enter the index";
                cin >> index;
                deleteAtindex(index);
              }
              break;
    }
  }
}

int main() {
	doublyLinkedList myDLL;
	myDLL.menu();

//	system("pause");
	return 0;
}
