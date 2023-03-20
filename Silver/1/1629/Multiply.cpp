#include <iostream>

typedef long long  UINT;
using namespace std;

UINT power(UINT base,UINT exp, UINT div);

int main(void){
  UINT base,exp,div;
  scanf("%lld %lld %lld",&base,&exp,&div);
  if(exp==0){
    printf("1");
    return 0;
  }
  UINT result = power(base,exp,div);
  printf("%lld",result);
}

UINT power(UINT base, UINT exp, UINT div){
  if(exp == 1){
    return base%div;
  }
  if(exp %2==0){
    return ( (power(base,exp/2,div)%div) * (power(base,exp/2,div)%div))%div;
  }
  else{
    return ((power(base,(exp-1)/2,div)%div) * (power(base,(exp-1)/2,div)%div) * base%div)%div;
  }
}