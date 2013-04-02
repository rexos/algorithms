#include "sort.h"
#include <iostream>
#include <stdio.h>
#include <fstream>


using namespace std;

int main(){
  int dim;

  ifstream in("input2.txt");
  in >> dim;

  int ary[dim];
  int bry[dim];
  for(int i=0; i<dim; i++){
    int tmp;
    in >> tmp;
    ary[i] = tmp;
    bry[i] = tmp;
  }  
  mergesort(ary,0,9);

  int min = ary[dim-1];
  int n = 0;
  int m = 0;
  for(int i=0; i<dim-1; i++){
    if(ary[i+1]-ary[i] < min){
      min = ary[i+1] - ary[i];
      n = ary[i];
      m = ary[i+1];
    }
  }

  int i=0;
  int j=0;
  for(int k=0; k<dim; k++){
    if(bry[k] == n){
      i=k;
    }
    else if(bry[k] == m){
      j = k;
    }
  }

  cout << i << "   " << j << endl;
  in.close();
  return 0;
}
