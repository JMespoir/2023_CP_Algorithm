#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
map<int,vector<int>> graph;
vector<bool> b(7,true);
void linkGraphNode(int a,int b){
  graph[a].push_back(b);
  graph[b].push_back(a);
}

void DFS(int start,int search){
  b[start] = false;
  cout << "[" << start << "]\n";
  if(start==search){
    return;
  }
  for(int i=0;i<graph[start].size();i++){
    if(b[graph[start][i]]){
      DFS(graph[start][i],search);
    }
  }
}

int BFS(int start,int search){
  queue<int> r;
  int count =1;
  int t;
  b[start] = false;
  r.push(start);
  while(!r.empty()){
    t=r.front();
    r.pop();
    if(t==search){
      return count;
    }
    for(int i=0;i<graph[t].size();i++){
      if(b[graph[t][i]]){
        r.push(graph[t][i]);
        count ++;
        b[graph[t][i]] = false;
      }
    }
  }
  return -1;
}

int main(void){
  linkGraphNode(1,2);
  linkGraphNode(1,4);
  linkGraphNode(1,6);
  //linkGraphNode(2,3);
  linkGraphNode(2,6);
  linkGraphNode(4,5);
  linkGraphNode(5,6);
  
  cout << BFS(1,4);



}