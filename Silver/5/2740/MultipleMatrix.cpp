#include <iostream>
#include <vector>
using namespace std;

int main(void){
  

  int N,M,m,n;
  int in;
  int temsum;

  cin >> N >> M;
  vector<vector<int>> A(N);
  for(int i =0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> in;
      A[i].push_back(in);
    }
  }

  cin >> m >> n;
  vector<vector<int>> B(m);
  vector<vector<int>> C(N);
  for(int i =0;i<m;i++){
    for(int j=0;j<n;j++){
      cin >> in;
      B[i].push_back(in);
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<n;j++){
      temsum=0;
      for(int t=0;t<M;t++){
        temsum += (A[i][t] * B[t][j]);
      }
      C[i].push_back(temsum);
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<n;j++){
      cout << C[i][j] << ' ';
    }
    cout << '\n';
  }
}