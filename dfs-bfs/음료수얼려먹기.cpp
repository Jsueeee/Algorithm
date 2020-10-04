#include <iostream>
#include <vector>

using namespace std;

int n, m;
int graph[1000][1000];

bool dfs(int x, int y){
  //범위체크
  if(x<0 || x>n || y<0 || y>m){
    return false;
  }

  //현재 노드 아직 방문 안했으면
  if(graph[x][y] == 0){
    //해당 노드 방문 처리 //방문처리와 칸막이 존재 부분을 1로 통합
    graph[x][y] = 1;

    //상하좌우 재귀 함수 호출
    dfs(x-1, y);
    dfs(x, y-1);
    dfs(x+1, y);
    dfs(x, y+1);
    return true;
  }
  return false;
}

int main() {
  cin>>n>>m;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &graph[i][j]);
    }
  }

  //모든 노드에 대하여 음료수 채우기
  int result = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(dfs(i, j)){
        //dfs 한 번 수행해서 음료수 묶음 개수세기
        result += 1;
      }
    }
  }
  cout<< result <<'\n';
  
}