#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int result;
int arr[8][8];
int temp[8][8];//벽 설치 후 맵

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


//dfs 이용 바이러스 사방으로 퍼지도록
//벽 설치가 끝난 맵인 temp에서.
void virus(int x, int y){
  for(int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx >= 0 && nx < n && ny >= 0 && ny <m){
      if(temp[nx][ny] == 0){
        temp[nx][ny] = 2;
        virus(nx, ny);
      }
    }
  }
}

int getScore(){
  int score = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(temp[i][j] == 0){
        score += 1;
      }
    }
  }
  return score;
}

//dfs 이용, 울타리 설치하면서 매 번 안전 영역의 크기 계산
void dfs(int count){
  //울타리가 3개 설치된 경우
  if(count == 3){
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        temp[i][j] = arr[i][j];
      }
    }
    //각 바이러스의 위치에서 전파 진행
    for(int i=0; i<n; i++){
     for(int j=0; j<m; j++){
        if(temp[i][j] == 2){
          virus(i, j);
        }
      }
    }
    //안전 영역의 최대값 계산
    result = max(result, getScore());
    return;
  }


  //빈 공간에 벽 설치
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(arr[i][j] == 0){
        arr[i][j] = 1;
        count += 1;
        dfs(count);
        //return 다음
        arr[i][j] = 0;
        count -= 1;
      }
    }
  }
}

int main(){
  cin>>n>>m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>arr[i][j];
    }
  }

  dfs(0);
  cout<< result <<'\n';
}