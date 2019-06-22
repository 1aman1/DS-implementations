#include<bits/stdc++.h>
using namespace std;
/*
 * class {
 * };*/
/*
 * struct {
 * };
 * */

void calcSpan( int prices[], int size, int span[] ){
  stack<int> S;
  S.push(0);
  span[0] = 1;//default span initialised

  for( int i = 1; i < size; ++i){
    while ( !S.empty() && prices[i] >= prices[S.top()] ) 
      S.pop();

    span[i] = ( S.empty() ? i +1 : i - S.top() ) ;

    S.push( i );
  }
}

int main(){ 
  int stockPrices[] = {10, 4, 5, 90, 120, 80};
  int  n = sizeof(stockPrices)/ sizeof(stockPrices[0]); 
  int span[n] ;
  calcSpan( stockPrices,n , span );

  for( auto &e : span ) cout << e << " ";
  
  cout<< endl;

  return 0;
}
