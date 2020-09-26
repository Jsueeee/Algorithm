#include <iostream>
#include <vector>

using namespace std;

int n;
int ugly[1000];

int main() {
  //못생긴 수에 2,3,5를 곱한 수도 또 못생긴 수가 된다는 게 포인트
  cin>>n;

//2배, 3배, 5배를 위한 인덱스
  int i2=0, i3=0, i5=0;

  //처음에 곱셈 값을 초기화
  int next2 = 2, next3 = 3, next5 = 5;

  ugly[0] = 1; //첫번째 못생긴 수는 1

  for(int k=1; k<n; k++){
    //가능한 곱셈 결과 중 가장 작은 수 선택
    ugly[k] = min(next2, min(next3, next5));

    //인덱스에 따라서 곱셈 결과를 증가
    // 2, 4, 6, 8, 10, 12, 14....
    // 3, 6, 9, 12, 15, 18, ...
    //5, 10, 15, 20, 25, 30 ...
    //얘네를 ugly 리스트에 배열하는 것.

    if(ugly[k] == next2){
      i2 += 1;
      next2 = ugly[i2] * 2; //다음 값
    }
    if(ugly[k] == next3){
      i3 += 1;
      next3 = ugly[i3] * 3;
    }
    if(ugly[k] == next5){
      i5 += 1;
      next5 = ugly[i5] * 5;
    }
  }
  cout<< ugly[n-1] <<'\n';
}