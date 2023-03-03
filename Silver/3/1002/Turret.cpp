#include <iostream>
#include <cmath>

enum{
  x_1,y_1,r_1,x_2,y_2,r_2
};

using namespace std;

void checkArr(int* arr);
int checkIn(int* arr, double range);

int main(void){
  int T;
  cin >> T;
  int** arr = new int*[T];
  for(int i=0;i<T;i++){
    arr[i] = new int[6];
    cin >> arr[i][x_1] >> arr[i][y_1] >> arr[i][r_1] >> arr[i][x_2] >> arr[i][y_2] >> arr[i][r_2];
  }
  for(int i = 0;i<T;i++){
    checkArr(arr[i]);
    cout << "\n";
  }
}

void checkArr(int* arr){
  double range = sqrt(pow(arr[x_1]-arr[x_2],2) + pow(arr[y_1]-arr[y_2],2));
  int big =arr[r_1] >arr[r_2] ? arr[r_1]:arr[r_2];
  int small = arr[r_1]<arr[r_2] ? arr[r_1]:arr[r_2];
  if(checkIn(arr,range)){
    if(range == 0 && arr[r_1] == arr[r_2]){
      cout << "-1";
    }
    else if(range +small< big){
      cout << "0";
    }
    else if(range+small ==  big){
      cout << "1";
    }
    else{
      cout << "2";
    }
  }
  else{
    if(range == arr[r_1]+arr[r_2]){
      cout << "1";
    }
    else if(range > arr[r_1]+arr[r_2]){
      cout << "0";
    }
    else{
      cout << "2";
    }
  }
}

int checkIn(int* arr, double range){
  if( range < (arr[r_1] > arr[r_2] ? arr[r_1] : arr[r_2])){
    return 1;
  }
  return 0;
}