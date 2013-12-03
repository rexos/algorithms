include <iostream>

using namespace std;

int prices[] = {1,3,2,4,6};
int data[6];

int main(){
  data[0] = 0;

  for( int i = 1; i < 6; i++ )
    data[i] = -10;

  for( int i = 1; i < 6; i++ ){
    int tmp = data[i];
    for( int j = 1; j <= i; j++ ){
      tmp = max( tmp, prices[j-1] + data[i-j] );
    }
    data[i] = tmp;
  }

  for( int i = 0; i < 6; i++ ){
    cout << data[i] << endl;
  }
  
  return 0;
}
