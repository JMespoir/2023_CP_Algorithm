#include <iostream>

using namespace std;

int main(void){
  int N,count;
  int* primes = new int[246913];
  primes[0] = primes[1] = 0;
  for(int i =2;i<246913;i++){
    primes[i] = 1;
  }
  for(int i =2;i<246913;i++){
    if(primes[i]){
      for(int j = 2*i;j<=246913;j+=i){
        primes[j] = 0;
      }
    }
  }

  while(1){
    count = 0;
    cin >> N;
    if(N==0){
      break;
    }
    for(int i=N+1;i<=2*N;i++){
      if(primes[i]){
        count+=1;
      }
    }
    cout << count << '\n';
  }

}