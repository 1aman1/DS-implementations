/*        this project demonsrtates singly linked list implementation      */
#include<iostream>
using namespace std;

struct SLL_Node {
	int value;
	SLL_Node* next;
	
  SLL_Node(int x):value(x), next(NULL)
	{}
};

class SinglyLinkedList {
  private:
    SLL_Node* head;	
    size_t SL_Size;

  public:

    SinglyLinkedList():head(NULL), SL_Size(0)	
  {}
    ~SinglyLinkedList()	{}
    /*
       cout<<__FUNCTION__<<endl;
       SLL_Node* pre = NULL;
       SLL_Node* post = head;
       while(NULL != post) {
       pre = post;
       post = post->next;
       cout<<"Deleting:"<<pre->value<<"\n";
       delete pre;
       }
       cout<<"List destructed\n:";
     */

    void print();

    size_t size_fn();
    void size_plus();
    void size_minus();
    void sizeIsZero();

    bool addAtFront( int );
    bool addAtEnd( int );
    bool addAtPosition( int, size_t);

    bool deleteAtFront();
    bool deleteAtEnd();
    bool deleteAtPosition( size_t );
    bool deleteNodeWithValue(int delValue);

    bool reverse();
    SLL_Node* removeAll(SLL_Node*);
    bool emptylist(int);

    int menu();
};

bool SinglyLinkedList::emptylist(int item){
  if(head) {
    SLL_Node* ptr = head;
    while( ptr->value !=  item)
      ptr = ptr->next;				
    removeAll(ptr);
  }
  else {
    print();
  }
  return true;
}

SLL_Node* SinglyLinkedList::removeAll(SLL_Node* targetNode) {
 	SLL_Node* current = targetNode;
	SLL_Node* Next = NULL;
	while(current != NULL) {
		Next = current->next;
		cout<<"[DELETING]-"<<current->value<<endl;
		free(current);
		current = Next;
    size_minus();
	}
  targetNode->next = NULL;
	return targetNode;
  //*/
}

void SinglyLinkedList::size_plus() {
  ++SL_Size;
}

void SinglyLinkedList::size_minus() {
  if( SL_Size > 0 )
    --SL_Size;
}

size_t SinglyLinkedList::size_fn() {
  return SL_Size;
}

void SinglyLinkedList::sizeIsZero() {
  SL_Size = 0;
}

void SinglyLinkedList::print() {
	SLL_Node* traverse = head;
	if(head == NULL) {
		cout<<"__EMPTY-LIST__";
		return;
	}
	else {
		cout<<"Elements are ";
		while(traverse != NULL) {
			cout<<traverse->value<<" : ";
			traverse = traverse->next;
		}
	}
	cout<<"END\n";
}

bool SinglyLinkedList::reverse() {
	SLL_Node* current = head;
	SLL_Node* prev = NULL;
	SLL_Node* Next = NULL;
	while(current != NULL) {
    Next = current->next;
    current->next = prev;
		prev = current;
		current = Next;
	}
	head = prev;
	cout<<"\tLIST REVERSED\n";
	return true;
}

bool SinglyLinkedList::deleteNodeWithValue(int delValue) {
	size_t count = 1;
	SLL_Node* traverse = head;

	while(traverse->value != delValue) {
		++count;
		traverse = traverse->next;
	}
	if(count == 1)
		deleteAtFront();		
	else if(count == size_fn())
		deleteAtEnd();
	else
    deleteAtPosition(count);
	
  return true;
}

bool SinglyLinkedList::deleteAtFront() {
	if(head == NULL) {
		cerr<<"__LIST EMPTY__\n";
		return false;
	}
	
	SLL_Node* firstNode = head;
	head = firstNode->next;
  delete firstNode;
  cout<<"\tDELETED\n";

  size_minus();
  return true;
}	

bool SinglyLinkedList::deleteAtEnd() {
  if(head != NULL && head->next == NULL)
    deleteAtFront();
  else if(head) {
    SLL_Node* LastNode = head;
    SLL_Node* temp = NULL;
    while(LastNode->next != NULL) {	
      temp = LastNode;
      LastNode = LastNode->next;
    }	
    temp->next = NULL;
    delete LastNode;
    cout<<"\tDELETED\n";

    size_minus();
    return true;
  }
  else {
    cerr<<"__LIST EMPTY__\n";
    return false;
  }
}

bool SinglyLinkedList::deleteAtPosition(size_t index) {
  if(index == 1)
    deleteAtFront();
  else if(index == size_fn())
    deleteAtEnd();	
  else {
    size_t count = 1;
    SLL_Node* preptr = NULL;
    SLL_Node* _remove = head;

    while(count < index) {
      preptr = _remove;
      _remove = _remove->next;
      ++count;
    }

    preptr->next = _remove->next;
    delete _remove;
    cout<<"\tDELETED\n";

    size_minus();
    return true;
  }		
}

bool SinglyLinkedList::addAtFront(int newValue) {
  SLL_Node* newNode = new SLL_Node(newValue);
  if(head == NULL){
    head = newNode;
  }		
  else{	
    newNode->next = head;
    head = newNode; 		
  }
  size_plus();
  return true;
}

bool SinglyLinkedList::addAtEnd(int newValue) {
  SLL_Node* newNode = new SLL_Node(newValue);
  SLL_Node* traverse = head;

  while(traverse->next != NULL) {	
    traverse = traverse->next;
  }	

  traverse->next = newNode;
  size_plus();	
  return true;
}

bool SinglyLinkedList::addAtPosition(int newValue,size_t index ) {
  if(index == 1)
    addAtFront(newValue);
  else if(index > size_fn())
    addAtEnd(newValue);
  else {
    SLL_Node* newNode = new SLL_Node(newValue);

    size_t count = 1;
    SLL_Node* indexPtr = head;
    SLL_Node* indexMinus1Ptr = NULL;
    while(count != index) {
      ++count;
      indexMinus1Ptr = indexPtr;
      indexPtr = indexPtr->next;
    }
    indexMinus1Ptr->next = newNode;
    newNode->next = indexPtr;
    size_plus();
  }
  return true;
}

int SinglyLinkedList::menu() {
  int more = 1;
  int choice = 0;
  while(more) {
    cout<<"\n 0 for Exit\n"
      <<"  1 add at front\n"
      <<"  2 add at @ index\n"
      <<"  3 add at end\n"
      <<"  4 Print the list\n"
      <<"  5 Size\n"
      <<"  6 Delete first element\n"
      <<"  7 Delete at @ index\n"
      <<"  8 Delete last element\n"
      <<"  9 Delete the specified element\n"			
      <<" 10 Reverse the list\n" 
      <<" 11 Remove list from a given node\n"
      <<" 12 Remove full list\n"
      <<"\nI m choosing  :  ";

    cin>>choice;
    cout<<"\n";
    switch(choice) {
      case 0: {
                more = choice;
                cout<<"\a";
              }
              break;
      case 1:	{
                int value;
                cout<<"Enter value : ";
                cin>>value;
                addAtFront(value);
              }
              break;
      case 2: {
                int newValue, index;
                cout<<"\nthe value : ";
                cin>>newValue;
                cout<<"\nindices [ 1 : 2 : 3 : so on ]\nat index : ";
                cin>>index;
                addAtPosition(newValue, index);
              }
              break;
      case 3: {
                int value;
                cout<<"Enter value : ";
                cin>>value;
                addAtEnd(value);
              }
              break;
      case 4: {
                cout<<"-->";
                print();
              }
              break;
      case 5: {
                cout<<"\nsize : "<<size_fn()<<"\n";
              }
              break;
      case 6: {
                deleteAtFront();
              }
              break;
      case 7: {
                size_t index;
                cout<<"enter the index ";
                cin>>index;
                deleteAtPosition(index);
              }
              break;
      case 8: {
                deleteAtEnd();
              }
              break;
      case 9: {
                int value;
                cout<<"Enter value : ";
                cin>>value;
                deleteNodeWithValue(value);
              }
              break;
      case 11: {
                 int item;
                 cout<<"\nfill node value that should persist\t";
                 cin>>item;
                 emptylist(item);
               }
               break;
      case 10: {
                 if(head) {
                   if( size_fn() >1 ) 
                     reverse();
                   print();
                 }
               }
               break;
      case 12: {
                 if(head)
                   removeAll(head);
                 else
                   print();
               }
               break;
      default: {
                 cerr<<"\ninvalid input\n";	
               }	break;
    }
  }
}

int main() {
  SinglyLinkedList runSLL;
  runSLL.menu();
  return 0;
}
