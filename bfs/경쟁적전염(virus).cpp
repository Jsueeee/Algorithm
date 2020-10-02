#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Virus{
  public:
    int index;//바이러스 종류
    int time;//시간(초)
    int x;// 위치
    int y;
    Virus(int index, int time, int x, int y){
      this->index = index;
      this->time = time;
      this->x = x;
      this->y = y;
    }
    //정렬 기준은 번호가 낮은!! 순서
    bool operator <(Virus &other){
      return this->index < other.index;
    }
};

int n, k;
//전체 보드 정보가 담긴 배열
int graph[200][200];
//바이러스가 담긴 리스트
vector<Virus> viruses;

//상하좌우 움직임
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main(){
  cin>>n>>k;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>graph[i][j];
      if(graph[i][j] != 0 ){
        //바이러스 종류, 시간, x, y 위치 
        viruses.push_back(Virus(graph[i][j], 0, i, j));
      }
    }
  }
  //인덱스 순 정렬
  sort(viruses.begin(), viruses.end());

  //정렬 후, 큐 삽입
  //Virus형 큐
  queue<Virus> q;
  for(int i=0; i<viruses.size(); i++){
    q.push(viruses[i]);
  }

  int target_s, target_x, target_y;
  cin>>target_s>>target_x>>target_y;

  //bfs
  while(!q.empty()){
    Virus virus = q.front();
    q.pop();

    //시간 종료 조건
    if(virus.time == target_s)  break;

    for(int i=0; i<4; i++){
      int nx = virus.x + dx[i];
      int ny = virus.y + dy[i];

      if(nx>=0 && nx<n && ny>=0 && ny<n){
        if(graph[nx][ny] == 0){
          graph[nx][ny] = virus.index;//바이러스 종류 저장하고 있는 index
          q.push(Virus(virus.index, virus.time +1, nx, ny ));
        }
      }
    }
  }
  cout<<graph[target_x-1][target_y-1];
}