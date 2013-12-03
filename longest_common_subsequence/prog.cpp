#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int ** tab;

int sol( string s, string t, int i, int j ){
  if( i < 0 || j < 0 )
    return 0;
  else if( i >= 0 && j >= 0 && s[i] == t[j] )
    return 1 + sol( s, t, i-1, j-1 );
  else{
    if( tab[i][j] != -1 )
      return tab[i][j];
    else
      return tab[i][j] = max( sol(s,t,i-1,j), sol(s,t,i,j-1) );
  }
}


int main(){
  ifstream in( "input.txt" );
  ofstream out( "output.txt" );
  string s;
  string t;
  in >> s >> t;

  tab = new int * [s.size()];
  for( int i=0; i<s.size(); i++ ){
    tab[i] = new int[t.size()];
  }

  for(int i=0; i<s.size(); i++){
    for( int j=0; j<t.size(); j++ )
      tab[i][j] = -1;
  }

  int value = sol(s,t,s.size()-1,t.size()-1);
  out << value << endl;

  return 0;
}
