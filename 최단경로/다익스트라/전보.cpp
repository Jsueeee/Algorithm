#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, start;
//각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int, int> > graph[30001];

//최단 거리 테이블
int d[30001];

int dijkstra(int start){
  priority_queue<pair<int, int> > pq;
  pq.push({0, start});  //{최단 경로 비용, 목적지노드}
  d[start] = 0;

  while(!pq.empty()){
    //가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
    int dist = -pq.top().first;//현재 노드까지의 비용
    int now = pq.top().second;//현재 노드
    pq.pop();

    //현재 노드가 이미 처리된 적이 있으면 무시
    if(d[now] < dist) continue;

    //현재 노드와 연결된 다른 인접한 노드들 확인
    for(int i=0; i<graph[now].size(); i++){
      int cost = dist + graph[now][i].second;

      //현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
      if(cost < d[graph[now][i].first]){
        d[graph[now][i].first] = cost;
        pq.push(make_pair(-cost, graph[now][i].first));
      }
    }
  }
}

int main() {
  cin>>n>>m>>start;
  
  for(int i=0; i<m; i++){
    int x, y, z;
    cin>>x>>y>>z;
    //x노드에서 y노드로 가는 비용 z
    graph[x].push_back({y, z});
  }

  //최단거리테이블 무한으로 초기화
  fill(d, d+30001, 1e9);

  dijkstra(start);

  //도달할 수 있는 노드의 개수
  int count = 0;

  //도달할 수 있는 노드 중에서, 가장 멀리 있는 노드와의 최단거리
  int maxDistance = 0;

  for(int i=1; i<=n; i++){
    //도달할 수 있는 경우
    if(d[i] != 1e9){
      count += 1;
      maxDistance = max(maxDistance, d[i]);
    }
  }

//시작 노드는 제외하므로 count -1
  cout<<count -1 <<' ' << maxDistance;

}