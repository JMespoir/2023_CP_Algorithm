#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a,int b){
  return a>b;
}

int main(void){

  int N;
  cin >> N;
  int sum=0;
  int *A = new int[N];
  int *B = new int[N];
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  for(int i=0;i<N;i++){
    cin >> B[i];
  }
  sort(A,A+N);
  sort(B,B+N,desc);
  for(int i=0;i<N;i++){
    sum+=A[i]*B[i];
  }
  cout << sum;

}