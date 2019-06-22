#include<bits/stdc++.h>
#define SIZE 5
using namespace std;

class _stack{
  public:
    int capacity;
    int top;
    int* stackArr;
};

void __function__(string p, string q ){
  cout << setw(19)<< left << p << "\t\t[ " << q << " ]\n";
}

_stack* createStack() {
  _stack* object = new _stack;
  if( !object ){
    __function__("no Memory Available", __FUNCTION__ );
    return NULL;
  }
  else{
    object->top = -1;
    object->capacity = SIZE;
    object->stackArr = new int[object->capacity * sizeof(int)];
    if( !object->stackArr ){
      __function__("no Memory Available", __FUNCTION__ );
      return NULL;
    }
    return object;
  }
}

void deleteStack( _stack* object ){
  if( object ){
    if( object->stackArr )
      delete object->stackArr;
    delete object;
  }
}

bool isStackEmpty( _stack* object ){
  return object->top == -1;
}

bool isStackFull( _stack* object ){
  return object->top == object->capacity -1;
}

void push( _stack* object, int item ){
  if( isStackFull( object ) ){
    __function__("_stack full", __FUNCTION__ );
  }
  else
    object->stackArr[++object->top] = item;
}

int pop( _stack* object ){
  if( isStackEmpty( object ) ){
    __function__("_stack full", __FUNCTION__ );

    return INT_MIN;
  }
  else
    return object->stackArr[ object->top-- ];
}

void topOfStack( _stack* object ){
  if( isStackEmpty( object ) ){
    __function__("_stack full", __FUNCTION__ );
  }
  else
    cout << "top:" << object->stackArr[ object->top ] << endl;
}
/*
   void doubleStack( _stack* object ){
   int arr[object->capacity];
   copy_n( object->stackArr, object->capacity, arr );
   object->capacity *= 2;
   object->stackArr = new int[object->capacity * sizeof(int)];
   copy_n( arr, object->capacity /2, object->stackArr);
   }
 */
int main() {
  _stack* top = createStack();

  push( top, 1 );
  push( top, 2 );
  push( top, 3 );
  push( top, 4 );

  //doubleStack( top );
  push( top, 200 );

  topOfStack( top );

  cout << pop( top ) << endl;
  cout << pop( top ) << endl;
  cout << pop( top ) << endl;
  return 0;
}
