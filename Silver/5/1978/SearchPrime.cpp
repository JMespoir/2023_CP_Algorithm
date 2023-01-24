#include <iostream>

using namespace std;



int main(void){
  int N,count = 0;
  int prime[1001];

  prime[0] = 0;
  prime[1] = 0;
  for(int i = 2;i<=1000;i++){
    prime[i] = 1;
  }
  for(int i = 2; i<=1000;i++){
    if(prime[i] == 1){
      for(int j = i+i;j<=1000;j = j+i){
        prime[j] = 0;
      }
    }
  }

  cin >> N;
  int* arr = new int[N];
  if(!arr){
    return 0;
  }

  for(int i =0;i<N;i++){
    cin >> arr[i];
  }

  for(int i =0;i<N;i++){
    if(prime[arr[i]]==1){
      count ++;
    }
  }
  cout << count;




}