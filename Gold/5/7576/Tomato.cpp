#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int arr[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int zerocount =0;
queue<pair<int,int>> q;

bool fun(int r,int c,int row, int col){
  if(r<0 || r>=row){
    return false;
  }
  if(c<0 || c>=col){
    return false;
  }
  return true;
}

int BFS(int row, int col, vector<vector<int>> v){
  int count =0;
  pair<int,int> tem;
  bool exit = true;
  int size =0;
  
  while(exit){
    count ++;
    exit=false;
    size = q.size();
    for(int i=0;i<size;i++){
      tem = q.front();
      q.pop();
      for(int j=0;j<4;j++){
        if(fun(tem.first+arr[j][0],tem.second+arr[j][1],row,col) && v[tem.first+arr[j][0]][tem.second+arr[j][1]]==0){
          q.push(make_pair(tem.first+arr[j][0],tem.second+arr[j][1]));
          v[tem.first+arr[j][0]][tem.second+arr[j][1]] = 1;
          zerocount --;
          exit = true;
        }
      }
    }
  }
  return count;
}

int main(void){
  int row,col;
  int tem;
  int minuscount=0;

  cin >> col >> row;

  vector<vector<int>> v(row,vector<int>(col));
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      scanf("%d",&tem);
      v[i][j] = tem;
      if(tem==1){
        q.push(make_pair(i,j));
        continue;
      }
      if(tem==-1){
        minuscount++;
        continue;
      }
      zerocount++;
      
    }
  }
  if(!zerocount){
    cout << 0;
    return 0;
  }
  if(!q.size()){
    cout << -1;
    return 0;
  }
  int count = BFS(row,col,v);
  if(zerocount){
    cout << -1;
    return 0;
  }
  else{
    cout << count-1;
    return 0;
  }
  
  



}