#include <fstream>
#include <iostream>
using namespace std;


int first(int * a,int i ,int dim){
  while(i<dim && a[i]<0){
    i++;
  }
  return i;
}


int main(){
  int dim;

  ifstream in("input.txt");
  ofstream out("output.txt");
  in>>dim;
  int a[dim];
  for (int j=0; j<dim; j++){
    in >> a[j];
  }



  int left,max,i=0;
  while(i<dim){
    if(left + a[i] > 0){
      left +=a[i];
      if(left > max) max = left;
    }
    else {i=first(a,i,dim); left=a[i]; if (left > max) max=left;}
    i++;
  }




  out << "yayyyhhhh!!";
  return 0;
}
