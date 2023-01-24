#include <iostream>

using namespace std;

int main(void){
  int m,M;
  int sum=0,min=0;
  cin >> m >> M;
  int* prime = new int[M+1];
  prime[0] = prime [1] = 0;
  for(int i =2;i<=M;i++){
    prime[i] = 1;
  }

  for(int i = 2;i<=M;i++){
    if(prime[i] == 1){
      for(int j = i+i;j<=M;j =j+ i){
        prime[j] = 0;
      }
    }
  }

  for(int i = m;i<=M;i++){
    if(prime[i]){
      sum += i;
      if(!min){
        min = i;
      }
    }
  }

  if(sum){
    cout << sum << endl << min;
  }
  else{
    cout <<-1;
  }

}