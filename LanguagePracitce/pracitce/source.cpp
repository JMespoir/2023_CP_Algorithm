#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int N;  
  cin >> N;

  vector<vector<int>> t(N,vector<int>(N));
  vector<vector<int>> T(N,vector<int>(N,0));
  vector<vector<vector<int>>> road(N,vector<vector<int>>(N,vector<int>(N,0)));
  // 삼각형 입력 
  for(int i=0;i<N;i++){
    for(int j=0;j<=i;j++){
      cin >> t[i][j];
    }
  }

  //0 따로 미리 선처리
  T[0][0] = t[0][0];
  road[0][0][0] = t[0][0];
  for(int i=1;i<N;i++){
    T[i][0] = t[i][0] + T[i-1][0];
    road[i][0]= road[i-1][0];
    road[i][0][i] = t[i][0];
  }


  // 
  for(int i=1;i<N;i++){
    for(int j=1;j<=i;j++){    
      if(T[i-1][j]>=T[i-1][j-1]){
        T[i][j] = t[i][j] + T[i-1][j];
        road[i][j]= road[i-1][j];
        road[i][j][i] = t[i][j];
      }
      else{
        T[i][j] = t[i][j] + T[i-1][j-1];
        road[i][j]= road[i-1][j-1];
        road[i][j][i] = t[i][j];
      }
    }
  }
//////////////////////

  int MAX = T[N-1][0];
  int index=0;
  for(int i=1;i<N;i++){
    if(MAX<=T[N-1][i]){
      MAX = T[N-1][i];
      index = i;
    }
  }
  int size = road[N-1][index].size();
  cout << MAX << endl;
  for(int i=0;i<size-1;i++){
    cout << road[N-1][index][i] << " ";
  }
  cout << road[N-1][index][size-1];

}