#include<bits/stdc++.h>
#define SIZE 1
using namespace std;
 
class Stack{
  public:
    int capacity;
    int top;
    int* stackArr;
};

void __function__( string s ){
	cout << "\t\t[ " << s << " ]\n";
}

Stack* createStack() {
  Stack* object = new Stack;
  if( !object ){
    cout << "no Memory" ;__function__(__FUNCTION__);
    return NULL;
  }
  else{
    object->top = -1;
    object->capacity = SIZE;
    object->stackArr = new int[object->capacity * sizeof(int)];
    if( !object->stackArr ){
      cout << "no Memory";__function__(__FUNCTION__);
      return NULL;
    }
    return object;
  }
}

void deleteStack( Stack* object ){
  if( object ){
    if( object->stackArr )
      delete object->stackArr;
    delete object;
  }
}

bool isStackEmpty( Stack* object ){
  return object->top == -1;
}

bool isStackFull( Stack* object ){
  return object->top == object->capacity -1;
}

void push( Stack* object, int item ){
/*  if( isStackFull( object ) ){
    cout << "stack Full";__function__(__FUNCTION__);
  }
  else */
    object->stackArr[++object->top] = item;
}

int pop( Stack* object ){
  /*if( isStackEmpty( object ) ){
    cout << "stack Empty";__function__(__FUNCTION__);
    return INT_MIN;
  }
  else */
    return object->stackArr[ object->top-- ];
}

void topOfStack( Stack* object ){
/*  if( isStackEmpty( object ) ){
    cout << "stack Empty";__function__(__FUNCTION__);
  }
  else*/
    cout << "top:" << object->stackArr[ object->top ] << endl;
}
/*
void doubleStack( Stack* object ){
  int arr[object->capacity];
  copy_n( object->stackArr, object->capacity, arr );
  object->capacity *= 2;
  object->stackArr = new int[object->capacity * sizeof(int)];
  copy_n( arr, object->capacity /2, object->stackArr);
}
*/
int main(){
  //prototype / emulation
// push( root0fStack, 1 );
// topOfStack( root0fStack );
// pop( root0fStack );
// isStackEmpty( root0fStack)
// isStackFull ( root0fStack)
// 
  Stack* top = createStack();
  string s;
  size_t i = 0;

  cin >> s;
  char *seq = new char[sizeof(s)];
  strcpy( seq , s.c_str() );
  while( seq[i] != 'X' ){
    push ( top, seq[i++] );
    topOfStack( top );
  }
  i++;
  while( seq[i] ){
    topOfStack( top );
    if( !( pop( top ) != seq[i]  )){
      ++i;
      continue;
    }
    cout <<"oops..! i dont wanna say it\n";
    return 0;
  }
  return 0;
}
