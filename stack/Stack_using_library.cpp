#include<bits/stdc++.h>

using namespace std;

void shoutOut( string Here ) {
  std::transform( Here.begin(), Here.end(), Here.begin(), ::toupper );
  cout << Here << endl;
}

int main() {
  shoutOut( __FUNCTION__ );
  stack<int> Mystack;

  cout << "stack";
  Mystack.empty() == true ?   cout << " is " : cout << " is not ";
  cout << "empty" << endl;
  
  for( int i= 0; i <= 4; ++i )	
    Mystack.push(i);
  cout << "pushed few elements" << endl;

  cout << "stack";
  Mystack.empty() == true ?   cout << " is " : cout << " is not ";
  cout << "empty" << endl;

  cout << "stack size is : " << Mystack.size()  << endl;

	cout << "\nstack top is " << Mystack.top()  << endl;

	Mystack.pop();		//since it has no return type
	Mystack.pop();		//since it has no return type

  cout << "popped few elements" << endl;
  cout << "stack top is " << Mystack.top() << endl;

  //system("pause");
	return 0;
}
