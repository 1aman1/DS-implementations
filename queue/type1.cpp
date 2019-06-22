// _queue.cpp 
#include<iostream>
using namespace std;

struct q_node {
	int data;
	q_node* next;
	
	q_node(int x):data(x), next(NULL)
	{}
};


class queue {
  private:
    q_node* front;
    q_node* rear;
    int size;

  public:
    void menu();
    void enqueue(int);
    void dequeue();
    size_t size_fn();
    void isempty();
};

void queue::menu() {
  front = rear = NULL;
  size = 0;
  cout << "queue using linkedlist\n";
  int element, more = 1, choice;
  while(more) {	
    cout << "\n0 for exit"
      << "\n 1 Enqueue an element"
      << "\n 2 Dequeue an element"
      << "\n 3 print the queue"
      << "\n 4 print size"
      << "\n 5 is queue empty !"
			<< "\nEnter the choice\n";	
			cin >> choice;
			switch(choice) {
				case 0: {
                  more = choice;
                }
                break;
        case 1: {
                  cout << "\nenter the element  : "; 
                  cin >> element;
                  enqueue(element);
                }
                break;
        case 2: {
                  dequeue();
                }
                break;
        case 3: {
                  cout << endl;
                  q_node* traverse = front;
                  if( traverse == NULL ) {
                    cout << "\nQUEUE_EMPTY ";
                  }
                  else {
                    while(traverse != NULL) {
                      cout << traverse->data << "-->";
                      traverse = traverse->next;
                    }
                    cout<<"REAR";
                  }
                  cout << endl;
                }
                break;
        case 4: {
                  cout << "\nsize is:" << size_fn() << "\n";
                }
                break;
        case 5: {
                  isempty();
                }
                break;
        default: {
                   cerr<<"invalid input\t";
                 }
                 break;
      }
  }
}

void queue::enqueue(int element) {
  q_node* newNode = new q_node(element);
  if(front == NULL) {
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

void queue::dequeue() {		
	if(front  == NULL) {
		cout << "____QUEUE_EMPTY____\n";
	}
	else {
    q_node* _remove = front;
    front = front->next;
    delete _remove;
    cout << "deleted\n";
		--size;
	}
}	
	
size_t queue::size_fn() {
  return size;
}

void queue::isempty() {
	if( size == 0 )
    cout << "QUEUE_EMPTY\n";
	else
    cout << "QUEUE_NOT_EMPTY, size is " << size_fn() << "\n";
}

int main() {	
	queue runMyQueue;
	runMyQueue.menu();
	system("pause");
	return 0;
}
