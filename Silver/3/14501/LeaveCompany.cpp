//NO!!

#include <iostream>
#include <vector>
#include <algorithm>

int g_max(0);
using namespace std;

enum{
  T,P
};

void DFS(vector<vector<int>> TP, int N,int tem, int count);

int main(void){
  int N;
  cin  >> N;
  vector <vector<int>> TP(N+1,vector<int>(2));
  TP[0][T] = 1;
  TP[0][P] = 0;
  for(int i =1;i<=N;i++){
    cin >> TP[i][T] >> TP[i][P];
  }

  DFS(TP,N,0,0);
  cout << g_max;
}

void DFS(vector<vector<int>> TP, int N,int tem,int count){
  if(count+TP[count][T]>N){
    if(g_max<tem){
      g_max = tem;
    }
    return;
  }
  else if(count==N && TP[count][T]==1){
    if(g_max<tem+TP[count][P]){
      g_max = tem + TP[count][P];
    }
    return;
  }
  for(int i=count+TP[count][T];i<=N;i++){
    DFS(TP,N,tem+TP[count][P],i);
  }


}