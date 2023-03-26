#include <iostream>

typedef long long int LI;
using namespace std;
LI gcd(LI M, LI m);

int main(void){
  LI N,M;
  LI GCD;
  cin >> N >> M;

  GCD = gcd(N>M?N:M,N>M?M:N);
  cout << (N*M / GCD);
}

LI gcd(LI M,LI m){
  if(m==0){
    return M;
  }
  return gcd(m,M%m);
}