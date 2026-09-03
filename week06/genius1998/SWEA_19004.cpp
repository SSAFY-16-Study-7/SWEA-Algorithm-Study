#include <iostream>
#include <tuple>
#include <cstring>
#include <queue>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

int n, k;
struct pos 
{
	int y; 
	int x; 
};
int INF = 10e8; //졸라 큰 수

int main() {
	int T;
	int n, k;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> k;
		unordered_map<int, vector<pos>> poses; // 각 인덱스에는 좌표 구조체가 저장됨.
		// 즉, dp[i] = {{0, 1}, {2, 3} ,... } 와 같은 형태
		// dp 정의.
		vector<vector<vector<int>>> dp(
			k + 1,
			vector<vector<int>>(
				n,
				vector<int>(n, INF)
				)
		); // 즉, dp[i][y][x] 로 접근 가능. 최소를 구해야하는 문제이므로 INF 초기값 설정.
		int grid[51][51];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
				pos tmp;
				tmp.y = i;
				tmp.x = j;
				poses[grid[i][j]].push_back(tmp);
				if (grid[i][j] == 1) {
					dp[1][i][j] = 0; // 1에서 시작했을때는 누적거리가 0
				}
			}
		}
		if (k == 1) {
			cout << "#" << tc << " " << 0 << "\n";
			continue;
		}
		// 1이 적힌 좌표에서 시작하므로 해당 좌표는 0으로 초기화
		int min_value = INF;
		// 여기까지 각 값에대한 좌표배열이 완성됨
		for (int i = 1; i <= k-1; i++) {
			for (auto ele : poses[i]) { // poses[i] 의 모든 좌표에 대해서 순회함.
				for (auto ele2 : poses[i+1]) { // 즉, 값이 i인 모든 좌표와 i+1인 모든 좌표를 순회
					int y1 = ele.y;
					int x1 = ele.x;
					int y2 = ele2.y;
					int x2 = ele2.x;
					int dist = abs(y2 - y1) + abs(x2 - x1); // 맨해튼 거리
					dp[i + 1][y2][x2] = min(dp[i + 1][y2][x2], dp[i][y1][x1] + dist);
					if (i + 1 == k) {
						min_value = min(min_value, dp[i + 1][y2][x2]);
					}
				}
			}
		}
		if (min_value == INF) {
			cout << "#" << tc << " " << -1 << "\n";
		}
		else {
			cout << "#" << tc << " " << min_value << "\n";
		}
	}
	return 0;
}
