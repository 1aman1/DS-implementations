#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef vector<short> Vec;

void MAKESET(Vec &set ) {
  for( short i = 0; i< 25; ++i )
    set[i] = -1;
}

short FIND( Vec set, short X ) {
//  cout << __FUNCTION__ << endl;
  
  if( X<0 || X >= set.size() )
    return SHRT_MIN;
  
  if( set[X] < 0 )
    return X;

  return FIND(set, set[X]);
}

void UNION( Vec& set , short root1, short root2) {
  //cout << __FUNCTION__ << endl;
  root1 = FIND( set, root1 ), root2 = FIND( set, root2 );
  if( root1  == root2 )
    return;
  //union 
  //to be parent root1 should have comparatively lesser no of elements,
  //that is,,,root1 > root2, 
  if( set[root1] > set[root2] ) {
    set[root1] = root2;
    set[root2] = -( abs(set[root2]) + abs( set[root1] ) );
  }
  else {
    set[root1] = -( abs(set[root2]) + abs( set[root1] ) );
    set[root2] = root1;
 }
}

int main() {
  Vec set(25);
  short option = 1, choice, X, Y;
  MAKESET( set );
  while( option ) {
    cout << "\n1-find\n2-union\n[INPUT] :";
    cin >> choice;
    switch( choice ) {
      case 1:{
               cout << "f\n[INPUT]-";
               cin >> X;
               cout << "[RESULT]->" << FIND( set, X) << endl;
               break;  }
      case 2:{
               cout << "u\n[INPUT]-";

               cin >> X >> Y;
               UNION( set, X, Y);
               break; }
      case 3:{
               for( auto& i:set )
                 cout << i << " ";
               option = 1;
               break;}
    }
  }
  cout << endl;
  return 0;
}
