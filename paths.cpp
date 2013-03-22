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
vector<int> pointed;
int count = 0;
deque<int> path;
int minimum;

void view(int start,int n, int end){
  if( !graph[n].found ){
    ary[n]--;
    pointed[n]--;
    cout << "pointed : ";
    for(int i=0; i<10; i++){
      cout << pointed[i] << " ";
    }
    cout << endl;

    cout << "visited : " << n << endl;
    if(n!=start)
      path.push_back(n);
    
    for(int i=0; i<graph[n].adj.size(); i++){
      int tmp = graph[n].adj[i];
      view(start,tmp, end);
    }
    if(n != end && ary[n] == 0 ){
      graph[n].found = true;
       cout << "FOUND : " << n << endl;
    }
    //cout<< "path size : " << path.size() << "  and minimum "<< minimum<<endl;
    if(n == end){
      if(path.size()==minimum)
	count++;
      int asd = path.front();
      cout << "ASD : " << asd <<endl;
      while(!path.empty()){
	cout << path.front() << "  ";
	path.pop_front();
      }
      cout << endl;
      path.clear();
      if(pointed[asd]>0){
	pointed[asd]--;
	path.push_front(asd);
      }
    }
  }
}



int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  
  int nodes,archs,start,end;
  in >> nodes >> archs >> start >> end;
  int tmp_ary[nodes];
  ary = tmp_ary;
  
  graph.resize(nodes);
  pointed.resize(nodes);
  for(int i=0; i<nodes; i++){
    ary[i]=0;
    pointed[i] = 0;
  }
  for(int i=0; i<archs; i++){
    int index,val;
    in >> index >> val;
    graph[index].adj.push_back(val);
    graph[index].erdos = 0;
    graph[val].erdos = 0;
    ary[val]++;
    pointed[index]++;
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
  
  for(int i=0; i<nodes; i++){
    graph[i].found = false;
    //cout << ary[i] << " ";
  }

  minimum = graph[end].erdos;
  view(start,start, end);
  cout << minimum <<endl;
  out << minimum  << " " << count;

  return 0;
}
