#include <iostream>

#define ARY_DIM 11
using namespace std;


int main(){
  int ary[ARY_DIM];
  
  int s[] = {2,100,4,6,7,15,2,36, 100, 150, 201};
  
  // table init
  for( int i = 0; i < ARY_DIM; i++ )
    ary[i] = 0;
  ary[0] = 1;

  int ind = 0;
  int r = s[ind];

  for( int i = 1; i < 11; i++ ){
    int cur = s[i];
    for( int j = ind; j < i; j++ ){
      r = s[j];
      if( cur >= r*2 and r*3 >= cur){
	r = s[i];
	ary[i] = ary[j] + 1;
	ind = i;
      }
      else{
	r = s[ind];
      }
    }
    ary[i] = ary[ind];
  }

  cout << ary[ARY_DIM - 1] << endl;
  

  return 0;
}
