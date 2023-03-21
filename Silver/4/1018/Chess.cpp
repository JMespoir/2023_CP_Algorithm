#include <iostream>
#include <vector>

using namespace std;



int main(void){
  int N, M;
  int min = 32;
  char color[3]= {'W','B'};
  int Check;
  int tem;
  cin >> N >> M;
  vector <vector<char>> v(N,vector<char>(M));

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> v[i][j];
    }
  }

  for(int startRow=0;startRow<=N-8;startRow++){
    for(int startCol=0;startCol<=M-8;startCol++){

      Check= (v[startRow][startCol] == color[0] ? 1 : 0);
      tem =0;
      for(int i=startRow;i<startRow+8;i++){
        Check = !Check;
        for(int j=startCol;j<startCol+8;j++){
          if(v[i][j] != color[Check]){
            tem++;
          }
          Check = !Check;
        }
      }

      if(tem>32){
        tem=64-tem;
      }
      if(min>tem){
        min =tem;
      }
    }
  }

  cout << min;
}