#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;
int n;
int cnt = 0;
int ans = 0;
int dxdy[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int arr[4][4];
bool is_valid(int y, int x) {
	return y >= 0 && y < 4 && x >= 0 && x < 4;
}
bool valid_num[10000000];
void dfs(int y, int x, int cnt, int cur_value) { // 각 row에서 n개의 col을 순회하면서 두었다고 가정
	if (cnt == 7) {
		if (!valid_num[cur_value]) {
			valid_num[cur_value] = true;
			ans++;
		}
		return;
	}
	int dx, dy, nx, ny;
	for (int i = 0; i < 4; i++) {
		dy = dxdy[i][0];
		dx = dxdy[i][1];
		ny = y + dy;
		nx = x + dx;
		if (is_valid(ny, nx)) {
			dfs(ny, nx, cnt + 1, cur_value*10 +arr[ny][nx]);
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		for (int j = 0; j < 4; j++) {
			for (int p = 0; p < 4; p++) {
				cin >> arr[j][p];
			}
		}
		ans = 0;
		fill(valid_num, valid_num + 10000000, false);
		for (int j = 0; j < 4; j++) {
			for (int p = 0; p < 4; p++) {
				dfs(j, p, 1, arr[j][p]); // 현재 칸을 포함하므로..
			}
		}
		cout << "#" << i << " " << ans << "\n";
	}

	return 0;
}
