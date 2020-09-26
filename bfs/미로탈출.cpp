#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int graph[201][201];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int x, int y){
  queue<pair<int, int> > q; //x와 y를 같이 저장할 큐
  q.push({x, y});

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    //현재 위치에서 4가지 방향으로 위치 확인
    for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      //범위 체크
      if(nx<0 || nx>=n || ny <0 || ny>=m) continue;

      //벽인 경우 무시
      if(graph[nx][ny] == 0)  continue;

      //해당 노드를 처음 방문하는 경우에만 최단 거리 기록
      if(graph[nx][ny] == 1){
        graph[nx][ny] = graph[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
  //가장 오른쪽 아래까지의 최단 거리 반환
  return graph[n-1][m-1];
}

int main() {
  cin>>n>>m;
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d", &graph[i][j]);
    }
  }

  cout<<bfs(0,0)<<'\n';
  
}