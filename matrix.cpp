#include <fstream>
#include <iostream>
using namespace std;





int main(){
  int r,c;
  ifstream in("input.txt");
  ofstream out("output.txt"); 
  in >> r >> c;
  int m[r][c];
  int tmp[r][c];
  // fill in my matrix bitch!! <3
  
  int count=0;
  for(int i=0; i<r; i++){
    count=0;
    for(int j=0; j<c; j++){
      in >> m[i][j];
      count += m[i][j];
      tmp[i][j]=count;
    }
  }
  
  
  int max=0;
  int sum=0;
  
  int i=0,j=0;
  

  for(int i=0; i<c; i++){
    for(int j=i; j<c; j++){
      
      for(int k=0; k<r; k++){
	int sum = tmp[r][j]-tmp[r][i]
      }
    }
  }
  
  
  
  out << max;
    
  return 0;
}



