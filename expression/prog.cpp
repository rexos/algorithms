#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> C;
vector<char> O;
int **M;
int nums;

void print(){
  for(int i=0; i<nums; i++){
    for(int j=0; j<nums; j++){
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
}

int calculate(int n, int m, char op){
  switch(op){
  case '+' : return n+m;
  case '*' : return n*m;
  }
}


void minexp(){
  for(int i=0; i<nums; i++)
    M[i][i] = C[i];
  for(int h = 1; h<nums; h++){
    for(int i=0; i<nums-h; i++){
      int j = h + i;
      M[i][j] = 1000;
      for(int k=i; k<j; k++){
	int t = calculate(M[i][k],M[k+1][j],O[k]);
	if(M[i][j] > t){
	  M[i][j] = t;
	}
      }
    }
  }
  print();
}


int main(){
  ifstream in("input.txt");
  in >> nums;
  C.resize(nums);
  O.resize(nums-1);
  int i = 0;
  for(i; i<=nums -1 ; i++)
    in >> C[i] >> O[i];
  in >> C[i+1];
  i=0;

  M = new int*[nums];
  for(int i=0; i<nums; i++){
    M[i] = new int[nums+1];
  }

  minexp();

  return 0;
}
