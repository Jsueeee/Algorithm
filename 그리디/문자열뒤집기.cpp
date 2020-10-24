#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string str;

//둘 중 더 작은 게 답
int cnt0 = 0;//전부 0으로 바꾸는 경우
int cnt1 = 0;//전부 1로 바꾸는 경우

int main() {
	cin >> str;//sstream

	if (str[0] == '1') {
		cnt0 += 1;
	}
	else {
		cnt1 += 1;
	}

	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] != str[i + 1]) {
			//다음 수에서 1로 바뀌는 경우
			if (str[i + 1] == '1') cnt0 += 1;
			//다음 수에서 0으로 바뀌는 경우
			else cnt1 += 1;
		}
	}
	cout << min(cnt0, cnt1) << '\n';
}