#include <string>
#include <vector>

using namespace std;

bool visit[200];

void dfs(int start, vector<vector<int>> &computers){
    visit[start] = true; //시작 노드 방문
    for(int i=0; i<computers[start].size(); i++){
        //시작 노드에 연결된 노드 수만큼
        if(i == start)  continue; //자기 자신 만나면 그냥 다음 노드로 (이 조건 없어도 통과)
        if(computers[start][i] == 1 && !visit[i]){
            dfs(i, computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++){
        //방문한 적 없으면
        if(!visit[i]){
            answer += 1;//dfs 한 번 시작하는 게 네트워크 1개
            dfs(i, computers);
        }
    }
    return answer;
}