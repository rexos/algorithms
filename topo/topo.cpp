#include <fstream>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
  bool found;
  vector<int> adj;
  node () : found(false){} 
};


vector<node> graph;
vector<int> order;

void dfs(int n){
  if(!graph[n].found){
    graph[n].found = true;
    for(int i=0; i<graph[n].adj.size(); i++){
      int tmp = graph[n].adj[i];
      dfs(tmp);
    }
    order.push_back(n);
  }
}


int main(){
  
  ifstream in("input.txt");
  ofstream out("output.txt");
  int nodes, archs;
  in >> nodes >> archs;
  graph.resize(nodes);

  for(int i=0; i<archs; i++){
    int index,value;
    in >> index >> value;
    graph[index].adj.push_back(value);
  }
  
  for(int i=0; i< nodes; i++){
      dfs(i);
  }
  
  for(int i=order.size()-1; i>=0; i--){
    out << order[i] << " ";
  }

  return 0;
}
