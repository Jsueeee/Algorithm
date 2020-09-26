#include <iostream>
#include <vector>

using namespace std;

int n;
string str1, str2;

int main() {
  cin>>str1>>str2;
  int n = str1.size();
  int m = str2.size();

  //다이나믹 프로그래밍 : 2차원 dp 테이블 초기화
  vector<vector<int> > dp(n+1, vector<int>(m+1));

  //dp 테이블 초기값 설정
  for(int i=1; i<=n; i++){
    dp[i][0] = i;
  }
  for(int j=1; j<=m; j++){
    dp[j][0] = j;
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      //문자가 같다면 : 왼쪽 위 값 그대로
      if(str1[i-1] == str2[j-1]){
        dp[i][j] = dp[i-1][j-1];
      }
      else{
        //문자가 다르다면 : 세가지 중 최솟값 찾기
        //삽입(왼쪽), 삭제(위쪽), 교체(왼쪽 위 대각선) 중 하나
        dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) +1;
      }
    }
  }
  cout<<dp[n][m]; //테이블 가장 오른쪽 아래에 있는 값이 구하고자 하는 최소 연산횟수
  
}