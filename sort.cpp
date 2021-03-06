#include <vector>
#include <fstream>
using namespace std;



void merge(int ary[],int start,int middle, int end){
  int i=start, j=middle+1, k=start;
  int b[end];
  while(i<=middle && j<=end){
    if (ary[i]<=ary[j]){
	b[k] = ary[i];
	i++;
      }
    else {
      b[k] = ary[j];
      j++;
    }
    k++;
  }
  
  j=end;
  
  for(int h=middle; h>=i; h--){
    ary[j] = ary[h];
    j--;
  }
  
  for(int j=start; j<k; j++){
    ary[j] = b[j];
  }

}


void merge_sort(int ary[],int start, int end){
  if (start<end){
    int middle = (start+end)/2;
    merge_sort(ary,start,middle);
    merge_sort(ary,middle+1,end);
    merge(ary,start,middle,end);
  }
}


int main(){
  int dim;
  
  ifstream in("input.txt");
  ofstream out("output.txt");

  in >> dim;
  int ary[dim];
  for(int i=0; i<dim; i++){
    in >> ary[i];
  }
  
  merge_sort(ary,0,dim-1);

  for(int i=0; i<dim; i++){
    out << ary[i]<< " ";
  }
  
  return 0;
}
