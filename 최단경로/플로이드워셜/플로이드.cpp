#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9

using namespace std;

int n, m;
int graph[101][101];

int main() {
	cin >> n;
	cin >> m;

	//최단거리테이블 무한으로 초기화
	for (int i = 0; i < 101; i++) {
		fill(graph[i], graph[i] + 101, INF);
	}

	//시작도시와 도착도시가 같은 경우는 없다 -> 자기 자신 0으로 초기화
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a == b)	graph[a][b] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		//양방향고려
		int a, b, c;
		cin >> a >> b >> c;
		//시작도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다
		//->가장 짧은 시간이 걸리는 도시만 저장
		if (c < graph[a][b])	graph[a][b] = c;
	}

	//플로이드워셜
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			//도달할 수 없는 경우 0 출력
			if (graph[a][b] == INF) {
				cout << 0 << ' ';
			}
			else {
				cout << graph[a][b] << ' ';
			}
		}
		//행바꿈
		cout << '\n';
	}


}