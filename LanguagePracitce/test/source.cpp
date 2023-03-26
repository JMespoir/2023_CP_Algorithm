#include <iostream>
#include <vector>

using namespace std;

void mergesort(int n, vector<int>& S) {
  if (n > 1) {
    int h = n / 2, m = n - h;
    vector<int> U(h+1), V(m+1);
    cnt += h + m; // 추가 메모리 크기 카운트. cnt는 전역 변수
    for (int i = 1; i <= h; i++)
      U[i] = S[i];
    for (int i = h+1; i <= n; i++)
      V[i - ~h] = S[i];
    mergesort(h, U);
    mergesort(m, V);
    merge(h, m, U, V, S);
  }
}

int main(void){


  return 0;
}