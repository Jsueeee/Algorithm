#include <iostream>

using namespace std;

string input;

//L자 형태 이동 정의
int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[] = {-1, 1, -2, -2, -1, 1, 2, 2};

int main(){
  cin>>input;
  //입력은 a1 형태
  //atoi()쓰지 않고 문자형 숫자 -> 정수형으로 바꾸기
  //아스키코드상 문자 1 == 49, 문자 0 == 48이기 때문에, 49-48 == 1 이 됨
  int row = input[1] - '0';

  //문제에 1~8로 범위가 정해져 있다
  //a~h를 정수형 1~8로 사용하기 위한 계산
  int column = input[0] - 'a' + 1;

  int result = 0;
  //경우의 수 문제 -> 8가지 방향에 대하여 각 위치로 이동이 가능한지 모두 확인

  for(int i=0; i<8; i++){
    int nrow = row + dx[i];
    int ncolumn = column + dy[i];

    if(nrow >= 1 && ncolumn >= 1 && nrow <=8 && ncolumn <=8){
      result += 1;
    }
  }
  cout<<result <<'\n';
}