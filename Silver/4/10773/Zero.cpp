//2023-01-24
#include <iostream>
#include <stack>

using namespace std;

int main(void){
  int N,res=0;
  int input;
  stack<int> S;
  cin >>N;

  for(int i=0;i<N;i++){
    cin >> input;
    if(input){
      S.push(input);
    }
    else{
      S.pop();
    }
  }

  while(!S.empty()){
    res += S.top();
    S.pop();
  }
  cout << res;
}