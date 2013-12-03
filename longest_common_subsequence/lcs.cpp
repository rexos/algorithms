#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
  ifstream in("input.txt");
  string s,p;
  in >> s >> p;
  int data[s.size()+1][p.size()+1];

  for( int i = 0; i < s.size() + 1; i++ ){
    for( int j = 0; j < p.size() + 1; j++ ){
      data[i][j] = 0;
    }
  }
  
  for( int i = 1; i < s.size()+1; i++ ){
    for( int j = 1; j < p.size() + 1; j++ ){
      if( s[i-1] == p[j-1] )
	data[i][j] = 1 + data[i-1][j-1];
      else
	data[i][j] = max( data[i-1][j], data[i][j-1] );
    }
  }
  cout << data[s.size()][p.size()] << endl;

  int i = s.size();
  int j = p.size();
  while( data[i][j] != 0 ){
    if( data[i][j] == data[i-1][j])
      i--;
    else if( data[i][j] == data[i][j-1])
      j--;
    else{
      cout << s[i] << " ";
      j--;
      i--;
    }
  }

  return 0;
}
