#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, testCase;
int indegree[501];
bool graph[501][501];//노드 연결 간선 정보 true or false

int main() {
  cin>>testCase;

  for(int tc=0; tc<testCase; tc++){
    fill(indegree, indegree+501, 0);
    for(int i=0; i<501; i++){
      fill(graph[i], graph[i]+501, false);
    }

    cin>>n;

    //들어오는 순서가 등수이므로 벡터에 집어넣어서 인덱스 표시
    vector<int> v;

    for(int i=0; i<n; i++){
      int x;
      cin>>x;
      v.push_back(x);
    }

    //자기보다 낮은 등수의 노드를 가리키도록
    //1등->2등, 1등->3등, 1등->4등 식으로 모두 가리키도록 만든다
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        graph[v[i]][v[j]] = true;
        indegree[v[j]] += 1;
        //진입차수는 들어오는 것 1씩 증가
      }
    }

    //올해 변경된 순위 정보
    cin>>m;
    for(int i=0; i<m; i++){
      int a, b;
      cin>>a>>b;

      //간선 방향 뒤집기
      if(graph[a][b]){
        graph[a][b] = false;
        graph[b][a] = true;
        indegree[a] += 1;
        indegree[b] -= 1;
      }else{
        graph[a][b] = true;
        graph[b][a] = false;
        indegree[a] -= 1;
        indegree[b] += 1;
      }
    }

    //위상 정렬 시작
    vector<int> result;
    queue<int> q;

    for(int i=1; i<=n; i++){
      if(indegree[i] == 0){
        q.push(i);
      }
    }

    //위상정렬의 결과가 오직 하나인지 여부
    //문제에서 확실한 순위를 찾을 수 없는 경우 -> 위상정렬 결과가 여러개
    bool certain = true;

    //그래프 내 사이클이 존재하는지 여부
    //사이클 : 모든 원소를 방문하기 전에 큐가 빈다면 사이클이 존재 -> 사이클이 존재한다면 사이클에 포함되어 있는 원소 중에서 어떠한 원소도 큐에 들어가지 못함
    //문제에서 데이터에 일관성이 없어서 순위를 정할 수 없는 경우 -> 사이클
    bool cycle = false;

    for(int i=0; i<n; i++){
      
      //큐 비어있으면 사이클 발생한 것
      if(q.size() == 0){
        cycle = true;
        break;
      }

      //큐의 원소가 2개 이상이면 가능한 정렬 결과가 여러개라는 뜻
      if(q.size() >= 2){
        certain = false;
        break;
      }

      int now = q.front();
      q.pop();
      result.push_back(now);

//큐에서 원소 끄낸 다음 노드 출발 간선 그래프 모두 제거
      for(int j=1; j<=n; j++){
        if(graph[now][j]){
          indegree[j] -= 1;

          //새로운 진입차수 0이 되는 노드를 큐에 삽입
          if(indegree[j] == 0){
            q.push(j);
          }
        }
      }
    }
  if(cycle) cout<< "IMPOSSIBLE" <<'\n';
  else if(!certain) cout<<"?"<<'\n';
  else{
    for(int i=0; i<result.size(); i++){
      cout<<result[i]>>' ';
    }
    cout<<'\n';
  }

  }
}