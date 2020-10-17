#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    //인접, 연결, 서로 영향 -> 최적부분구조, 중복문제
    //인접한 두 집 털면 안되니까 -> 한칸씩 건너서
    //a(i) : 도둑이 i번째 집까지 훔칠 수 있는 돈의 최댓값
    //개미전사 문제와 유사
    
    vector<int> dp1(money.size(), 0); //처음 집을 훔치는 경우
    vector<int> dp2(money.size(), 0); //처음 집을 훔치지 않고, 두번째 집부터 훔치는 경우
    
    dp1[0] = money[0];
    dp1[1] = money[0];
    dp2[0] = 0;
    dp2[1] = money[1];
    
    for(int i=2; i<money.size(); i++){        
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i]);
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
        //점화식은 똑같다. 초기조건을 다르게 했으니 ok
    }
    //첫 집을 들렸으면 마지막집은 안들리므로, 그 전 항과 같다는 것을 예외처리해준다.
    dp1[money.size()-1] = dp1[money.size()-2];
    
    return max(dp1[money.size()-1], dp2[money.size()-1]);
}