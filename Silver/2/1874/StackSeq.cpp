// 2023-01-24 (Nope)
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main(void){
  int N,input,count = 0;
  stack<int> S;
  queue<char> Sc;
  cin >> N;
  int* arr = new int[N]();
  for(int i =0;i<N;i++){
    cin >> arr[i];
  }
  for(int i=1;i<=N;i++){
    S.push(i);
    Sc.push('+');
    while(!S.empty() && S.top() == arr[count]){
      Sc.push('-');
      S.pop();
      count ++;
    }
  }
  if(S.empty()){
    while(!Sc.empty()){
      cout << Sc.front() << '\n';
      Sc.pop();
    }
  }
  else{
    cout << "NO";
  }
}