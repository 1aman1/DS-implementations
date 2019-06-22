#include<iostream>
#include<algorithm>
#include<limits.h>
#include<string>
#define SIZE 3
using namespace std;
 
class _stackNode{
  public:
    _stackNode(int item):data(item), next(NULL){}
    int data;
    _stackNode* next;
};

void __function__( string s ){
	cout << "\t\t[ " << s << " ]\n";
}

_stackNode* createStack(){
  return NULL;
}

void deleteStack( _stackNode* top ){
  while( top ){
    _stackNode* temp = top;
    top = top->next;
    delete temp;
  }
  delete top;
}

void push( _stackNode** top,int item ){
  _stackNode* newNode =  new _stackNode(item);
  if( !newNode ){
    cout << "no Memory"; __function__(__FUNCTION__);}
  else{
    newNode->next = *top;
    *top = newNode;
  }
}

int pop( _stackNode** top ){
  if( !top ){
    cout << "stack Empty";__function__(__FUNCTION__);
    return INT_MIN;
  }
  else{
    _stackNode* temp;
    temp = *top;
    *top = (*top)->next;
    int data = temp->data;

    delete temp;
    return data;
  }
}

void topOfStack( _stackNode* top ){
  if( !top  ){
    cout << "stack Empty";__function__(__FUNCTION__);
  }
  else
    cout << "top:" << top->data<< endl;
}

int main(){
  _stackNode* top = createStack(); 

  push( &top, 1 );
  push( &top, 2 );
  push( &top, 3 );
  push( &top, 4 );
  push( &top, 500 );

  topOfStack( top );

  cout << "popped : " << pop( &top ) << endl;
  cout << "popped : " << pop( &top ) << endl;
  cout << "popped : " << pop( &top ) << endl;
  //system("pause");
  return 0;
}
