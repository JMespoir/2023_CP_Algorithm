#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
typedef pair<int,int> M2;

int arr[6][3] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}}; // f , r , c
int zerocount =0;

queue<pair<int,M2>> q;

bool isTrue(int r,int c,int f,int row, int col,int floor);
int BFS(int row, int col,int floor, vector<vector<vector<int>>> v);

int main(void){
  int row,col,floor;
  int tem;
  int minuscount=0;
  M2 matrix2;
  cin >> col >> row >> floor;
  vector<vector<vector<int>>> v(floor,vector<vector<int>>(row,vector<int>(col,0)));
  for(int f=0;f<floor;f++){
    for(int x=0;x<row;x++){
      for(int y=0;y<col;y++){
        scanf("%d",&tem);
        v[f][x][y] = tem;
        if(tem == -1){
          minuscount++;
          continue;
        }
        if(tem == 1){
          matrix2 = make_pair(x,y);
          q.push(make_pair(f,matrix2));
          continue;
        }
        zerocount ++;
      }
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

  int count = BFS(row,col,floor,v);

  cout << count;
  
}

bool isTrue(int r,int c,int f,int row, int col,int floor){
  if(r<0 || r>=row){
    return false;
  }
  if(c<0 || c>=col){
    return false;
  }
  if(f<0 || f>=floor){
    return false;
  }
  return true;
}

int BFS(int row, int col,int floor, vector<vector<vector<int>>> v){
  int count =0;
  pair<int,M2> tem;
  int size =q.size();
  int tr,tc,tf;
  while(size){
    count ++;
    for(int i=0;i<size;i++){
      tem = q.front();
      q.pop();
      for(int j=0;j<6;j++){
        tf = tem.first+arr[j][0];
        tr = tem.second.first+arr[j][1];
        tc = tem.second.second+arr[j][2];
        
        if(isTrue(tr,tc,tf,row,col,floor) && v[tf][tr][tc]==0){
          q.push(make_pair(tf,make_pair(tr,tc)));
          v[tf][tr][tc] = 1;
          zerocount --;
        }
      }
    }
    size=q.size();
    if(zerocount==0){
      return count;
    }
  }
  return -1;
}