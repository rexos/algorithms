#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <deque>


using namespace std;


struct node{
  bool found;
  vector<int> adj;
  int erdos;
  node() : found(false){}
};
  
vector<node> graph;  
queue<int> myqueue;
int *ary;
vector<int> pointing;
int count = 0;
deque<int> path;
int minimum;
int start,end;
vector<int> array;
int depth = -1;

void view(int n){  
  if(!graph[n].found){
    graph[n].found = true;
    depth++;
    cout << "visiting : " << n << endl;
    cout << "DEPTH : " << depth << endl;
    if(depth == minimum && n == end){
      count++;
    }
    else if (depth < minimum){
      for(int i=0; i<graph[n].adj.size(); i++){
	int tmp = graph[n].adj[i];
	cout << "father : " << n << endl;
	view(tmp);
      }
    }
    depth--;
    graph[n].found = false;
  }
}


int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  
  int nodes,archs;
  in >> nodes >> archs >> start >> end;
  int tmp_ary[nodes];
  ary = tmp_ary;
  
  graph.resize(nodes);
  pointing.resize(nodes);
  array.resize(nodes);
  for(int i=0; i<nodes; i++){
    ary[i]=0;
    pointing[i] = 0;
    array[i] = 0;
    //graph[i].adj.resize(nodes);
  }
  for(int i=0; i<archs; i++){
    int index,val;
    in >> index >> val;
    graph[index].adj.push_back(val);
    graph[index].erdos = 0;
    graph[val].erdos = 0;
    ary[val]++;
    pointing[index]++;
    array[index]++;
  }
  
  // getting minimum path lenght
  myqueue.push(start);
  graph[start].found = true;
  while(!myqueue.empty()){
    int cur = myqueue.front();
    myqueue.pop();
    for(int i=0; i<graph[cur].adj.size(); i++){
      int tmp = graph[cur].adj[i];
      if(!graph[tmp].found){
	graph[tmp].found = true;
	graph[tmp].erdos = graph[cur].erdos + 1;
	myqueue.push(graph[cur].adj[i]);
      }
    }
  }
  
  cout << "pointed : ";
  for(int i=0; i<nodes; i++){
    graph[i].found = false;
    cout << ary[i] << " ";
  }
  cout << endl;
    
  minimum = graph[end].erdos;
  view(start);
  
  out << minimum << " " << count;

  return 0;
}
