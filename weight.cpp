#include <iostream>
#include <fstream>

using namespace std;

void swap(int ary[],int i, int j){
  int temp= ary[i];
  ary[i]=ary [j];
  ary[j]=temp;
}

int index_of(int ary[], int dim, int target){
  int i=0;
  while(ary[i]!=target){
    i++;
  }
  return i;
}


int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int dim;
  
  in >> dim;
  int ary[dim];
  int bry[dim];
  for(int i=0; i<dim; i++){
    in >> ary[i];
    bry[i]=ary[i];
  }
  
  int swaps=0;
  int total=0;
  
  int min=1;


  for(int i=0; i<dim; i++){
    if(ary[i]!=min){
      swap(ary,i,index_of(ary,dim,min));
      
      swaps++;
    }
    min++;
  }
  
  min=1;
  
  
  for(int i=0; i<dim; i++){
    if((i+1)!=bry[i] && bry[bry[i]-1]==(i+1)){
      total += ((i+1)+bry[i]);
      swap(bry,i,bry[i]-1);
    }
  }

  
  int tmp=0;
  int sum=0;
  while(min<=dim){
    int index = index_of(bry,dim,min);
    if(min == index+1){
      min++;
    }
    else{
      while(index != min-1){
	total += index+1;
	sum += index+1;
	tmp++;
	swap(bry,index,index_of(bry,dim,index+1));
	index=index_of(bry,dim,min);
      }
      if((2*(1+min))+sum+tmp > (min*tmp)+sum){
	total += min*tmp;
      }
      else{
	total += (2*(1+min))+tmp;
      }
      tmp=0;
      sum=0;
      min++;
    }
  }
  


  out<<swaps<<" "<<total;
  
  return 0;
}
