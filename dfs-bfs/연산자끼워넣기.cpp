#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;
int add, sub, mul, divi;

int minValue = 1e9;
int maxValue = -1e9;

void dfs(int i, int now) {
	//연산자 개수는 숫자개수 -1
	//인덱스 혼용 위해 i=1부터 시작 후 n이랑 같아질 때까지
	if (i == n) {
		minValue = min(minValue, now);
		maxValue = max(maxValue, now);
	}
	else {
		if (add > 0) {
			add -= 1;
			dfs(i + 1, now + arr[i]);
			add += 1;
		}
		if (sub > 0) {
			sub -= 1;
			dfs(i + 1, now - arr[i]);
			sub += 1;//원상복귀
		}
		if (mul > 0) {
			mul -= 1;
			dfs(i + 1, now * arr[i]);
			mul += 1;
		}
		if (divi > 0) {
			divi -= 1;
			dfs(i + 1, now / arr[i]);
			divi += 1;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	cin >> add >> sub >> mul >> divi;

	dfs(1, arr[0]);

	cout << maxValue << '\n' << minValue << '\n';
}