#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> t;
vector<int> p;
int dp[16];
int maxValue;

int main() {
  cin>>n;

  for(int i=0; i<n; i++){
    int x, y;
    cin>>x>>y;
    t.push_back(x);
    p.push_back(y);
  }

//뒤에서부터 거꾸로 확인
  for(int i=n-1; i>=0; i--){
    int time = t[i] +i;

    //상담이 기간 안에 끝나는 경우
    if(time <= n){
      dp[i] = max(p[i] + dp[time], maxValue);
      //maxValue : 뒤에서부터 계산할 때, 현재까지의 최대 상담 금액
      maxValue = dp[i];
    }

    //상담이 기간을 벗어나는 경우 그냥 현재 최대 상담금액.
    else dp[i] = maxValue;
  }
  cout<< maxValue<<'\n';
}