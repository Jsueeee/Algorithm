#include <iostream>

using namespace std;

int n, m, x, y;
int direction;
//북동남서
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int arr[50][50];//맵 정보
int d[50][50];//방문체크

void rotate(){
  //왼쪽방향 회전 (반시계 방향 90도)
  direction -= 1;
  if(direction == -1) direction = 3;
}

int main() {
  cin>>n>>m;
  cin>>x>>y>>direction;

  d[x][y] = 1; //현재 위치 방문처리

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int a;
      cin>>a;
      arr[i][j] = a;
    }
  }

  int cnt = 1; //방문한 칸의 수 출력, 현재 칸 방문중이므로 1
  int turn_time = 0;

  //시뮬레이션 시작
  while(true){
    //1. 현재 방향 기준으로 왼쪽 회전, 갈 방향 정하기
    rotate();

    //다음 칸
    int nx = x + dx[direction];
    int ny = y + dy[direction];

    //2. 방문하지 않은 경우 & 육지 : 전진
    if(d[nx][ny] == 0 && arr[nx][ny] == 0){
      d[nx][ny] = 1;
      x = nx; //큐 안쓰고 시뮬로 움직이기
      y = ny;
      cnt += 1;
      turn_time = 0;
      continue;
    }else{
      //방문한 경우이거나, 바다인 경우
      turn_time += 1;
    }
    if(turn_time == 4){
      //네 방향 모두 이미 가 본 칸이거나 바다 칸이면
      //바라보는 방향 유지 & 한 칸 뒤로 & 1단계로 돌아가기
      nx = x - dx[direction];
      ny = y - dy[direction];
      //뒤가 바다라 못 가면 움직임 멈추기
      if(arr[nx][ny] == 1){
        break;
      }else{
        //갈 수 있으면
        x = nx;
        y = ny;
      }
      turn_time = 0;
    }
  }
  cout<<cnt<<'\n';
}