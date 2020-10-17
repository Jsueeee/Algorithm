#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int result, int cnt){
    if(cnt == numbers.size()){
        if(result == target)
            answer += 1;
        return;//얘가 위 if문 안에 있으면 에러
        //값이 같으면 ans++이고, 달라도 리턴으로 반복문은 끝내줘야 한다.
    }
    //numbers[cnt]로 for문 안쓰고도 재귀함수 구현 가능
    dfs(numbers, target, result + numbers[cnt], cnt+1);
    dfs(numbers, target, result - numbers[cnt], cnt+1);
}
int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    
    return answer;
}