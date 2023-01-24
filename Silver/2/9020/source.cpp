#include <iostream>

using namespace std;

int main(void){
  int T;
  int n;
  int primes[10001];
  primes[0] = primes[1] = 0;
  for(int i =2;i<10001;i++){
    primes[i] = 1;
  }
  for(int i=2;i<10001;i++){
    if(primes[i]){
      for(int j = 2*i;j<10001; j+=i){
        primes[j] = 0;
      }
    }
  }

  cin >> T;
  for(int i =0;i<T;i++){
    cin >> n;
    for(int j=n/2;j>=2;j--){
      if(primes[j] && primes[n-j]){
        cout << j << ' ' << n-j << '\n';
        break;
      }
    }
  }

}