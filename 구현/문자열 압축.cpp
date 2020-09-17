#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size(); //기본값 -> step = 0
    
//1개 단위부터 압축 시작
    for(int step=1; step<s.size()/2 + 1; step++){
        string compressed = "";
        
        //같은지 비교할 기준 문자
        string prev = s.substr(0,step);
        int cnt = 1;
        
        //j += step 중요
        for(int j = step; j<s.size(); j+= step){
            if(prev == s.substr(j, step)){
                cnt += 1;
            }else{
                compressed += (cnt>=2) ? to_string(cnt) + prev : prev;
                prev = s.substr(j, step);
                cnt = 1; //초기화
            }
        }
        //남은 문자열 처리
        compressed += (cnt>=2) ? to_string(cnt) + prev : prev;
        //가장 짧은 게 답
        answer = min(answer, (int)compressed.size());
    }
    return answer;
}