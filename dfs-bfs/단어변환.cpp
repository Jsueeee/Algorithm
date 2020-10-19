#include <string>
#include <vector>

using namespace std;

int answer = 100;
bool check[51];

void dfs(string begin, string target, vector<string>&words, int result){
    if(begin == target){
        answer = min(answer, result);
        return;
    }
    
    for(int i=0; i<words.size(); i++){
        int cnt = 0;
        for(int j=0; j<begin.size(); j++){
            if(begin[j] != words[i][j]) cnt++;
            if(cnt == 2)    break;
        }
        if(cnt == 1){
            if(check[i] == false){
                check[i] = true; //중요**
                dfs(words[i], target, words, result+1);
                check[i] = false; //중요****
            }
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    if(answer == 100)   return 0;
    return answer;
}