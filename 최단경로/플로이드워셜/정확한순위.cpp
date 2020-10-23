#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9

using namespace std;

int n, m;
int graph[501][501];

//최단 경로 문제
//학생들의 성적을 비교한 문제 -> 방향 그래프
//성적이 낮은 학생 -> 성적이 높은 학생 가리킴
//'경로'를 이용하여 성적 비교 가능
//A->B 도달 가능하다? -> A가 B보다 성적이 낮다!
//도달가능하면 성적 비교가 가능해지는 것
//도달 불가하면 성적 비교 불가능
//도달이 가능한지 체크
//자기 자신은 항상 도달 가능

int main() {
	cin >> n >> m;

	//최단거리 테이블 무한으로 초기화
	for (int i = 0; i < 501; i++) {
		fill(graph[i], graph[i] + 501, INF);
	}

	//자기자신 0 초기화
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a == b)	graph[a][b] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1; //비용은 모두 1
	}

	//플로이드
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	int result = 0;
	//도달 가능한지 체크
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] != INF || graph[j][i] != INF) {
				cnt += 1;
			}
		}
		//특정한 노드의 카운트 값이 N이라면, 해당 노드의 정확한 순위 알 수 있다는 뜻
		if (cnt == n) {
			result += 1;
		}
	}
	cout << result << '\n';

}