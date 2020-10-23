#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9

using namespace std;

int testCase;
int n;
int graph[125][125];
int d[125][125];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main() {
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> graph[i][j];
			}
		}

		//최단 거리 테이블 초기화
		for (int i = 0; i < n; i++) {
			fill(d[i], d[i] + 125, INF);
		}

		//(0,0)이 출발지
		int x = 0;
		int y = 0;

		//시작 노드로 가기 위한 최단 경로는 0
		priority_queue < pair<int, pair<int, int> > > pq;
		//첫번째 원소가 우선순위큐의 기준
		//최단경로 찾으므로 - 붙이기
		//최단경로길이, x, y 순
		pq.push({ -graph[x][y], {0, 0} });
		d[x][y] = graph[x][y];

		//다익스트라 알고리즘
		while (!pq.empty()) {
			int dist = -pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)	continue;
				
				int cost = dist + graph[nx][ny];

				//현재 노드 거쳐서 다른 노드로 이동하는 거리가 기존보다 더 짧은 경우
				if (cost < d[nx][ny]) {
					d[nx][ny] = cost;
					pq.push({ -cost, {nx, ny} });
				}
			}
		}
		cout << d[n - 1][n - 1] << '\n';
	}
}