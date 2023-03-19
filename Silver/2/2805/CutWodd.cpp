// 2023-03-17
#include <iostream>

using namespace std;
typedef long long int INT;
void SearchWood(INT N, INT M, INT* H, INT max);
INT checkMid(INT mid, INT* H,INT N,INT M);

int main(void){

  INT N,M , max = 0;
  cin >> N >> M;

  INT* H= new INT[N];
  for(INT i=0;i<N;i++){
    cin >> H[i];
    if(max < H[i]){
      max = H[i];
    }
  }

  SearchWood(N, M, H, max);
  

  return 0;
}

void SearchWood(INT N, INT M, INT* H,INT max){
  INT left = 1;
  INT right = max;
  INT mid;
  INT Max_wood = 0;

  while(left<=right){
    mid = (left+right)/2;

    if(checkMid(mid,H,N,M)){
      Max_wood = mid;
      left = mid+1;
    }
    else{
      right = mid-1;
    }
  }
  cout << Max_wood;
}

INT checkMid(INT mid,INT* H,INT N,INT M){
  INT sum=0;
  for(INT i =0;i<N;i++){
    sum += (H[i]-mid >0 ? H[i]-mid:0);
  }
  return (sum>=M);
}