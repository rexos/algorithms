#include <fstream>
#include <stdlib.h>
#include <utility>
#include <iostream>
#include <vector>
using namespace std;


struct nodo{
  bool found;
  vector<int> adj;
nodo() : found(false){}
    
};

vector<nodo> graph;

int count=0;

void view(int n){
  if(!graph[n].found){
    graph[n].found = true;
    count++;
    for(int k=0; k<graph[n].adj.size(); k++){
      view(graph[n].adj[k]);
    }
  }
}



int main(){
  
  
  ifstream in("input.txt");
  ofstream out("output.txt");
  int nodes;
  int archs;
  int start;
  
  in >> nodes >> archs >> start;
  
  graph.resize(nodes);
  for(int i=0; i<archs; i++){
    int index,val;
    in >> index >> val;
    graph[index].adj.push_back(val);
  }
   
  view(start);
  out<<count;
  
  return 0;
}
