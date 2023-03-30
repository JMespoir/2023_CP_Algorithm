#include <iostream>
#include <deque>
#include <string>


using namespace std;

int main(void){
  int T,N;
  string tem,arr,ans;
  deque<int> d;
  bool f=true;
  bool e= false;
  cin >> T;

  for(int i=0;i<T;i++){
    //초기화 함수
    f= true;
    e=false;
    d.clear();
    tem.clear();
    arr.clear();
    cin >> tem >> N >> arr;

    // 파싱함수
    for(int j=1;']'!=arr[j];j++){
      if(arr[j]==','){
        d.push_back(stoi(ans));
        ans.clear();
        continue;
      }
      ans.push_back(arr[j]);
    }
    if(ans.length()!=0){
      d.push_back(stoi(ans));
      ans.clear();
    }

    // D입력하는 함수
    for(int j=0;j<tem.length();j++){
      if(tem[j]=='D'){
        if(d.size()==0){
          e=true;
          break;
        }
        if(f){
          d.pop_front();
          continue;
        }
        d.pop_back();
        
      }
      else{
        f= !f;
      }
    }

    int D_SIZE = d.size();

    // 출력하는 함수
    if(e){
      cout << "error" << '\n';
    }
    else{
      cout << '[';
        if(f){
          for(int idx =0;idx<D_SIZE;idx++){
            cout << d[idx];
            if(idx != (D_SIZE-1)){
              printf(",");
            }
          }
        }
        else{
          for(int idx =(D_SIZE-1);idx>=0;idx--){
            cout << d[idx];
            if(idx != 0){
              printf(",");
            }
          }
        }
      cout << ']' << '\n';
    }
  }




}