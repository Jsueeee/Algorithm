#include <iostream>
#include <queue>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int arr[10][10];
int n;

void bfs(int x, int y){
	queue<pair<int, int> > q;
	q.push({x, y});
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			//범위 밖 무시
			if(nx < 0 || nx > n || ny < 0 || ny > n)	continue;
			//벽인 경우 무시
			if(arr[nx][ny] == 0)	continue;
			//갈 수 있으면
			if(arr[nx][ny] == 1){
				//지금까지의 최단 거리 저장
				arr[nx][ny] = arr[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
}
int main() {
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n ;j++){
			cin>>arr[i][j];
		}
	}
	bfs(0, 0);
	cout<<arr[n-1][n-1];
}