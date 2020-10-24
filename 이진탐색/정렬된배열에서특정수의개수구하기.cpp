#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x;
vector<int> v;

int count(vector<int> &v, int rightValue, int leftValue) {
	//정렬되어 있으므로 이진탐색 가능
	//(x, x) 범위 안의 개수를 찾는 것.
	vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
	vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
	return rightIndex - leftIndex;
}

int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	//값이 (x, x) 범위에 있는 데이터의 개수 계산
	int cnt = count(v, x, x);//0과 n-1 양쪽 끝부터 시작

	cout<<cnt;
}