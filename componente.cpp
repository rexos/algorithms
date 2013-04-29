#include <utility>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


struct node{
  bool found;
  bool marked;
  vector<int> adj;
  node() : found(false){}
};


vector<node> graph;
vector<node> trasp;

int counter = 0;

void dfs(int n){
  if(!graph[n].found){
    graph[n].found = true;
    trasp[n].marked = true;
    for(int i=0; i<graph[n].adj.size(); i++){
      int tmp = graph[n].adj[i];
      dfs(tmp);
    }
    //    graph[n].found = false;
  }
}

void dfstrasp(int n){
  if(!trasp[n].found){
    trasp[n].found = true;
    if (trasp[n].marked)
      counter++;
    for(int i=0; i<trasp[n].adj.size(); i++){
      int tmp = trasp[n].adj[i];
      dfstrasp(tmp);
    }
    //trasp[n].found = false;
    //trasp[n].marked = false;
  }
}

int main(){
  int nodes,archs;
  ifstream in("input.txt");
  ofstream out("output.txt");
  in >> nodes >> archs;
  graph.resize(nodes);
  trasp.resize(nodes);

  for(int i=0; i<archs; i++){
    int index,value;
    in >> index >> value;
    graph[index].adj.push_back(value);
    trasp[value].adj.push_back(index);
    trasp[index].marked = false;
    trasp[value].marked = false;
  }

  int max = 0;
  for(int i=0; i<nodes; i++){
    dfs(i);
    dfstrasp(i);
    if(counter > max)
      max = counter;
    counter = 0;
    for(int i=0; i<nodes; i++){
      trasp[i].marked = false;
      graph[i].found = false;
      trasp[i].found = false;
    }

  }

  out << max;
  
  return 0;
}
