#include<iostream>
#include<algorithm>
// #include <cstdio>
using namespace std;

int n;
bool visited1[40];
bool visited2[40]; // / 방향
bool visited3[40]; // 반대 방향
int answer = 0;

void dfs(int r) {
	if (r == n) {
		answer++;
		return;
	}
	for (int i = 0;i < n;i++) {
		if (visited1[i] || visited2[i + r] || visited3[r - i + n - 1]) continue;

		visited1[i] = 1;
		visited2[i + r] = 1;
		visited3[r - i + n - 1] = 1;
		dfs(r + 1);
		visited1[i] = 0;
		visited2[i + r] = 0;
		visited3[r - i + n - 1] = 0;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " ";
		answer = 0;
		cin >> n;

		dfs(0);

		cout << answer;
		cout << "\n";
	}
	return 0;
}
