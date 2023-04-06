#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> s;
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
        s.push(tem);
        continue;
      }
      if(tem==-1){
        minuscount++;
      }
    }
  }



}