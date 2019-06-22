#include<bits/stdc++.h>
#define SIZE 4 
using namespace std;

class _arrQueue{
  public:
    int capacity, front, rear;
    int* arr;
};

void __function__(string p, string q ){
  cout << setw(19)<< left << p << "\t\t[ " << q << " ]\n";
}

_arrQueue* createQueue(){
  _arrQueue* newNode = new _arrQueue;
  if ( !newNode ){
    __function__("no Memory Available", __FUNCTION__ );
    return NULL;
  }
  else{
    newNode->capacity = SIZE;
    newNode->front = newNode->rear = -1;
    newNode->arr = new int[newNode->capacity * sizeof(int)];
    if( ! newNode->arr ){
      __function__("no Memory Available", __FUNCTION__ );
      return NULL;
    }
    return newNode;
  }
}

bool isQueueEmpty(_arrQueue* qHandle ){
  return qHandle->front == -1 ;
}

bool isQueueFull(_arrQueue* qHandle ){
  return ( qHandle->rear + 1 ) % qHandle->capacity == qHandle->front ;
}

void enQueue( _arrQueue* qHandle, int data ){
  if( !qHandle || isQueueFull( qHandle ) ){
     __function__("no Memory Available", __FUNCTION__ );
  }
  else{
    qHandle->rear = (qHandle->rear +1) % qHandle->capacity;
    qHandle->arr[ qHandle->rear ] = data;
    if( qHandle->front == -1 )
      qHandle->front = qHandle->rear;
  }
}
//hey i know dequeue ought to return ,,,but therz a soft touch

void deQueue( _arrQueue* qHandle ){
  if( isQueueEmpty( qHandle ) ){
    __function__("queue empty", __FUNCTION__ );
  }
  else{
    cout << qHandle->arr[qHandle->front] << endl;
    qHandle->arr[qHandle->front] = -1;
    if( qHandle->front == qHandle->rear )
      qHandle->front = qHandle->rear = -1;
    else
      qHandle->front = ( qHandle->front +1 ) % qHandle->capacity;
  }
}

int main(){
  //BRIEF :
  //enQueue ( qHandle, value )
  //deQueue( qHandle )
  //'-1' is a sentinel, hence not ideal for inserting

  _arrQueue* qHandle = createQueue();

  deQueue( qHandle );

  enQueue(  qHandle, 1 );
  enQueue(  qHandle, 2 );

  deQueue( qHandle );
  deQueue( qHandle );
  deQueue( qHandle );

  return 0;
}
