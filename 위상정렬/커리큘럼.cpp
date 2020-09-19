#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//노드의 개수
int v;
//모든 노드에 대한 진입차수 0 초기화
int indegree[501];
//간선 정보 저장할 연결 리스트 초기화
vector<int> graph[501];
//강의 시간 저장 0 초기화
int times[501];

void topologySort(){
  vector<int> result[501]; //결과 담을 리스트 - 정답이 모든 노드의 결과이므로
  for(int i=1; i<=v; i++){//배열 번호를 아예 인덱스로 쓰기 위해서 i=1부터
    result[i] = times[i];
  }

  queue<int> q;

  for(int i=1; i<=v; i++){
    //처음 시작. 진입차수가 0인 노드 큐에 삽입
    if(indegree[i] == 0) q.push(i);
  }

  while(!q.empty()){
    int now = q.front();
    q.pop();

    //now 노드에 연결된 노드들 다 방문
    //연결된 노드들의 진입차수에서 1빼기 (연결된 간선 제거)
    for(int i=0; i<graph[now].size(); i++){
      result[graph[now][i]] = max(result[graph[now][i]], result[now] + times[graph[now][i]]);

      indegree[graph[now][i]] -= 1;

      if(indegree[graph[now][i]] == 0){
        q.push(graph[now][i]);
      }
    }
  }

  for(int i=1; i<=v; i++){
    cout<<result[i]<<'\n';
  }

}

int main() {
  cin>>v;

  for(int i=1; i<=v; i++){
    int x;
    cin>>x;
    times[i] = x;

    while(true){
      cin>>x;
      if(x == -1) break;
      indegree[i] += 1; //진입차수 저장
      graph[x].push_back(i); //연결 노드 그래프 저장
    }
  }
  topologySort();
}