#include <iostream>

using namespace std;

int sum = 0;
string input;

int main(){
  cin>>input;
  
  for(int i=0; i<input.size()/2; i++){
    sum += input[i] - '0';
    //atoi()없이 문자형 숫자->정수형 숫자 변환하기
  }

  for(int i=input.size()/2; i<input.size(); i++){
    sum -= input[i] -'0';
  }

  if(sum == 0)  cout<<"LUCKY"<<'\n';
  else cout<<"READY"<<'\n';
}