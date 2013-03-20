#include <fstream>
#include <cstdlib>
#include <iostream>
#include <utility>
using namespace std;


void merge(pair<int,int> ary[],int start,int middle, int end){
  int i=start, j=middle+1, k=start;
  pair<int,int> b[end];
  while(i<=middle && j<=end){
    if (ary[i].second<=ary[j].second){
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


void merge_sort(pair<int,int> ary[],int start, int end){
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
  pair<int,int> gaps[dim];
  
  
  for(int i=0; i<dim; i++){
    in >> gaps[i].first;
    in >> gaps[i].second;
  }
 
  merge_sort(gaps,0,dim-1);
  
 
  int max = gaps[0].second;
  int diff=0;
  int max_diff=0;
  int x=0;
  int y=0;
  for(int i=1; i<dim; i++){
    if(max < gaps[i].first){
      diff=gaps[i].first - max;
      if(diff > max_diff){
	max_diff = diff;
	x=max;
	y=gaps[i].first;
      }
    }
    max = gaps[i].second;
  }
  out<<x<<" "<<y;
  return 0;
}
