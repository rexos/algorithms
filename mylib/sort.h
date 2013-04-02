#ifndef SORT_H
#define SORT_H


void merge(int *ary, int start, int middle, int end){
  int i=start, j=middle+1, k=start;
  int b[end];
  while(i<=middle && j<=end){
    if(ary[i]<=ary[j]){
      b[k] = ary[i];
      i++;
    }
    else{
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


void mergesort(int *ary,int start, int end){
  if (start < end){
    int middle = ( start + end ) / 2;
    mergesort(ary,0,middle);
    mergesort(ary,middle+1,end);
    merge(ary,start,middle,end);
  }
}


#endif
