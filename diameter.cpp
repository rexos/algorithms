#include <fstream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct node{
  bool found;
  int erdos;
  vector<int> adj;
  node() : found(false){}
};


vector<node> graph;
queue<int> myqueue;


int main(){
  int nodes, archs;
  ifstream in("input.txt");
  ofstream out("output.txt");

  in >> nodes >> archs;
  graph.resize(nodes);
  for(int i=0; i<archs; i++){
    int index,val;
    in >> index >> val;
    graph[index].adj.push_back(val);
    graph[val].adj.push_back(index);
    graph[index].erdos = 0;
    graph[val].erdos = 0;
  }

  int max = 0;
  for(int j=0; j<nodes; j++){
    int current = 0;
    myqueue.push(j);
    graph[j].found = true;
    while(!myqueue.empty()){
      int cur = myqueue.front();
      myqueue.pop();
      for(int i=0; i<graph[cur].adj.size(); i++){
	int tmp = graph[cur].adj[i];
	if(!graph[tmp].found){
	  graph[tmp].found = true;
	  graph[tmp].erdos = graph[cur].erdos + 1;
	  if ( max < graph[cur].erdos + 1 )
	    max = graph[cur].erdos + 1;
	  myqueue.push(graph[cur].adj[i]);
	}
      }
    }
    for(int k=0; k<nodes; k++){
      graph[k].erdos = 0;
      graph[k].found = false;
    }
  }
  out<<max;
  
  return 0;
}
