#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void){

  int T,count=0;
  int max=0;

  cin >> T;
  vector<int> N(T);

  for(int i=0;i<T;i++){
    cin >> N[i];
    if(max<N[i]){
      max = N[i];
    }
  }
  vector<bool> B(max+1,true);
  vector<int> C(max+1);

  B[0]=false;
  B[1]=false;
  for(int i=2;i<max+1;i++){
    if(B[i]==true){
      C[count++] = i;
      for(int j=i*2;j<max+1;j+=i){
        B[j] = false;
      }
    }
  }

  for(int i=0;i<T;i++){
    float T_count =0;
    for(int j=0;j<count;j++){
      if(C[j]>=N[i]){
        break;
      }
      if(B[N[i]-C[j]]){
        T_count++;
      }
    }
    cout << (int)(ceil(T_count/2)) << '\n';
  }

}