#include <iostream>
#include <tuple>
#include <cstring>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

int n, k;
struct object //  물건
{
	int v; // 부피
	int c; // 가치
};

int main() {
	int T;
	int n, k;
	cin >> T;
	int dp[1001];
	fill(dp, dp + 1001, -1); // -1로 초기화


	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> k;
		fill(dp, dp + 1001, -1); // -1로 초기화
		dp[0] = 0; //아무것도 고르지 않은 상태
		vector<object> arr; // 물건들
		for (int i = 0; i < n; i++) {
			object tmp;
			cin >> tmp.v;
			cin >> tmp.c;
			arr.push_back(tmp);
		}
		// 여기서부터 물건들을 역순 조회
		int max_value = 0;
		for (int i = 0; i < n; i++) {
			int cur_v = arr[i].v;
			int cur_c = arr[i].c;

			// 중복 선택을 방지하기 위해 역순으로 순회
			for (int j = k; j >= cur_v; j--) {
				// 이전 물건들로 j - cur_v 부피를 만들 수 있었다면
				if (dp[j - cur_v] != -1) {
					dp[j] = max(dp[j], dp[j - cur_v] + cur_c);
					max_value = max(max_value, dp[j]);
				}
			}
		}
		cout << "#" << tc << " " << max_value << "\n";
	}
	return 0;
}
