#include <iostream>
#include <vector>

using namespace std;

int main(void){
  long N;
  cin >> N;
  long Super=N;
  vector<long> A(N);
  long B,C;
  for(long i=0;i<N;i++){
    cin >> A[i];
  }
  cin >> B >> C;

  for(long i=0;i<N;i++){
    long tem = A[i]-B;
    if(tem<=0){
      continue;
    }
    if(tem % C == 0){
      Super += (tem /C);
    }
    else{
      Super += (tem/C)+1;
    }
  }
  cout << Super;

}