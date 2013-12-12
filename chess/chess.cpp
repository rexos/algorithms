#include <iostream>
#include <fstream>
using namespace std;


int main(){
  ifstream in("input.txt");
  int n;
  in >> n;
  int m[n][n];
  int tab[n+1][n+1];

  for( int i = 0; i < n+1; i++ ){
    tab[i][0] = 0;
    tab[0][i] = 0;
  }

  for( int i = 0; i < n; i++){
    for( int j = 0; j < n; j++ ){
      in >> m[i][j];
      tab[i+1][j+1] = -1;
    }
  }

  for( int i = 1; i < n+1; i++ ){
    for( int j = 1; j < n+1; j++ ){
      int p, q;
      if( i == 1 )
	q = tab[i][j-1];
      if( j == 1 )
	q = tab[i-1][j];
      if( i != 1 and j != 1 ){
	p = min( tab[i-1][j-1], tab[i-1][j] );
	q = min( p, tab[i][j-1] );
      }
      tab[i][j] = q + m[i-1][j-1];
    }
  }


  for( int i = 0; i < n+1; i++){
    for( int j = 0; j < n+1; j++ ){
      cout << tab[i][j] << "  ";
    }
    cout << endl;
  }

  return 0;
}
