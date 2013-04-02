#include <iostream>
#include <utility>
#include <vector>
#include <fstream>

using namespace std;

struct node{
  bool found;
  vector<int> adj;
};

vector<node> graph;


int main(){
  int nodes, archs;
  ifstream in("input.txt");
  ofstream out("output.txt");
  in >> nodes >> archs;
  graph.resize(nodes);
  int kings[nodes];
  for(int i=0; i< nodes; i++){
    kings[i] = 0;
  }
  for( int i=0; i<archs; i++ ){
    int index,value;
    in >> index >> value;
    graph[index].adj.push_back(value);
    graph[value].adj.push_back(index);
  }

  int count = 0;
  for(int i=0; i<nodes; i++){
    if(graph[i].adj.size()==1){
      count++;
      kings[i] = 1;
    }
  }
  out << count << endl;
  for(int i=0; i< nodes; i++){
    if(kings[i]==1){
      out << i << " ";
    }
  }
  in.close();
  out.close();
  return 0;
}
