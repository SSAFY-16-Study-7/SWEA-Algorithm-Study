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
	bool is_possible[10001];
	fill(is_possible, is_possible + 10001, false); // false로 초기화


	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		fill(is_possible, is_possible + 10001, false); // -1로 초기화
		is_possible[0] = true; //아무것도 고르지 않은 상태
		vector<int> arr; // 물건들
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			arr.push_back(num);
		}
		// 여기서부터 물건들을 역순 조회
		int max_value = 0;
		for (int i = 0; i < n; i++) {
			int cur = arr[i]; // 현재 점수
			// 중복 선택을 방지하기 위해 역순으로 순회
			for (int j = 10000; j >= 0; j--) {
				// 이전 물건들로 j - cur_v 부피를 만들 수 있었다면
				if (j - cur >= 0 && is_possible[j - cur]) {
					is_possible[j] = true; // j-cur이 있어야 j도 채울수 있음.
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i <= 10000; i++) {
			if (is_possible[i]) {
				cnt++;
			}
		}
		cout << "#" << tc << " " << cnt << "\n";
	}
	return 0;
}
