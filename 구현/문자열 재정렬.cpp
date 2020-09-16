#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string input;
vector<char> result;//결과 리스트
int value = 0;

int main(){
  cin>>input;

  for(int i=0; i<input.size(); i++){
    //알파벳인 경우 결과 리스트에 삽입
    if(isalpha(input[i])){
      result.push_back(input[i]);
    }else{
      value += input[i] - '0';
    }
  }  

  sort(result.begin(), result.end());
  
  for(int i=0; i<result.size(); i++){
    cout<<result[i];
  }
  if(value != 0) cout<<value;
}