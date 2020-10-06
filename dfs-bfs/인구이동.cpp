#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, r, l;

int graph[50][50];
int unions[50][50];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};


void process(int x, int y, int index){
  //(x, y)의 위치와 연결된 나라(연합) 정보를 담는 리스트
  vector<pair<int, int> > united;
  united.push_back({x, y});

  //bfs를 위한 큐 사용
  queue<pair<int, int> > q;
  q.push({x, y});

  //현재 연합의 번호 할당
  unions[x][y] = index;
  //현재 연합의 전체 인구 수
  int summary = graph[x][y];

  //현재 연합의 국가 수
  int count = 1;

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(0<=nx && nx<n && 0<=ny && ny<n && unions[nx][ny] == -1){
        int gap = abs(graph[nx][ny] - graph[x][y]);
        if(l <= gap && gap <= r){
          q.push({nx, ny});

          //연합에 추가
          unions[nx][ny] = index;
          summary += graph[nx][ny];
          count += 1;
          united.push_back({nx, ny});
        }
      }
    }
  }
  //연합 국가끼리 인구를 분배
  for(int i=0; i<united.size(); i++){
    int x = united[i].first;
    int y = united[i].second;
    graph[x][y] = summary/count;
  }
}
int result = 0;

int main(){
  cin>>n>>l>>r;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>graph[i][j];
    }
  }

  //더이상 인구이동 할 수 없을 때까지 반복
  while(true){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        unions[i][j] = -1;
      }
    }

    int index = 0;

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(unions[i][j] == -1){
          //아직 방문하지 않았으면
          process(i, j, index);
          index += 1;
        }
      }
    }

    //모든 인구이동이 끝나면
    if(index == n*n)  break;

    //계속 진행시
    result += 1;
  }
  cout<<result;
}