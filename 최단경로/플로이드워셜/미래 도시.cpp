#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, x, k;
int graph[101][101];

int main() {

	//최단거리 테이블을 모두 무한으로 초기화
	for (int i = 0; i < 101; i++) {
		fill(graph[i], graph[i] + 101, 1e9);
	}

	//자기 자신->자기 자신 거리는 0으로 초기화
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a == b)	graph[a][b] = 0;
		}
	}

	//정보 (양방향)
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	cin >> x >> k;

	//플로이드워셜 알고리즘 (a->k->x 점화식 사용)
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	int distance = graph[1][k] + graph[k][x];
	
	//도달할 수 없는 경우 -1 출력
	if (distance >= 1e9) {
		cout << "-1" << '\n';
	}
	else {
		cout << distance << '\n';
	}
}