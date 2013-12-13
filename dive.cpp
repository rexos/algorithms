#include <iostream>

using namespace std;


int main(){
  int c[4][4];
  for(int i = 0; i<4; i++)
    c[i][i] = 0;
  c[0][1] = 1;
  c[0][2] = 2;
  c[0][3] = 4;
  c[1][2] = 1;
  c[1][3] = 3;
  c[2][3] = 2;

  int ary[4];
  for( int i = 1; i < 4; i++ ){
    int q = 100;
    for( int k = 0; k < i; k++ ){
      q = min( q, ary[k]+c[k][i] );
    }
    ary[i] = q;
  }

  cout << ary[3] << endl;

  return 0;
}
