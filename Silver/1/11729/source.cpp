// 2023-01-24
#include <iostream>

using namespace std;

void printrecur(char start, char middle, char fin,int res);

int main(void){
  int N;
  int res=1;
  char start='1', middle = '2',fin='3';
  cin >> N;
  for(int i=0;i<N;i++){
    res *=2;
  }
  res -=1;
  
  cout << res << "\n";
  printrecur(start,middle,fin,N);
  return 0;
}

void printrecur(char start, char middle, char fin,int N){
  if(N>=1){
    printrecur(start,fin,middle,N-1);
    cout << start << ' ' << fin <<'\n';
    printrecur(middle,start,fin,N-1);
  }
}