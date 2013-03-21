#include <fstream>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct node{
  bool found;
  int erdos;
  vector<int> adj;
  node() : found(false){}
};


vector<node> graph;



void view(int n,int father_erdos){
  if(!graph[n].found || graph[n].erdos>father_erdos+1){
    graph[n].found = true;
    graph[n].erdos = father_erdos+1;
    for(int i=0; i<graph[n].adj.size(); i++){
      view(graph[n].adj[i],graph[n].erdos);
    }
  }
}

int main(){
  int nodes, archs;
  ifstream in("input.txt");
  ofstream out("output.txt");

  in>>nodes>>archs;
  graph.resize(nodes);
  for(int i=0; i<archs; i++){
    int index,val;
    in >> index >> val;
    graph[index].adj.push_back(val);
    graph[val].adj.push_back(index);
  }

  for(int i=0; i<nodes; i++){
    graph[i].erdos=1000000;
  }
  
  int max=0;
  int current=0;
  for(int i=0; i<nodes; i++){
    view(i,-1);
    
    for(int j=0; j<nodes; j++){
      if(graph[j].erdos > current){
	current = graph[j].erdos;
      }
      graph[j].erdos=1000000;
    }
    if(current > max) max = current;
    current =0;
  }
  
  out<<max;

  return 0;
}
