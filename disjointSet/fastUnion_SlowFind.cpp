#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef vector<short> Vec;

void MAKESET( Vec &set ) {
  for( short i = 0; i < 25; ++i )
    set[i] = i;
}

short FIND( Vec set, short X ) {
//  cout << __FUNCTION__ << endl;
  
  if( X<0 || X >= set.size() )
    return -1;
  
  if( set[X] == X )
    return X;

  return FIND(set, set[X]);
}

void UNION( Vec& set , short child, short parent) {
  //cout << __FUNCTION__ << endl;

  if( FIND( set, child ) == FIND( set, parent ) )
    return;

  set[child] = parent ;
}

int main() {
  Vec set(25);
  short option = 1, choice, X, Y;
  MAKESET( set );
  while( option ) {
    cout << "1-find\n2-union\n[INPUT] :";
    cin >> choice;
    switch( choice ) {
      case 1:{
               cout << "f\n";
               cin >> X;
               cout << FIND( set, X) << endl;
               break;  }
      case 2:{
               cout << "u\n";

               cin >> X >> Y;
               UNION( set, X, Y);
               break; }
      case 3:{
               option = 1;
               break;}
    }
  }
  //  for( auto& i:set )
  //  cout << i << " ";
  cout << endl;
  return 0;
}
