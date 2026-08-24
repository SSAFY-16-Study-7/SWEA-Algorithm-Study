#include<iostream>
#include<algorithm>
#include <bitset>
using namespace std;

int n;
double prob[20][20];
double memo[1 << 20];
bool visited_[1 << 20];

double dfs(int mask) {
	if (mask == (1 << n) - 1) return 1.0; // 전부 배정 완료: 더 곱할 게 없으니 1

	if (visited_[mask]) return memo[mask]; // 이미 계산한 적 있는 상태면 바로 반환

	int person = bitset<20>(mask).count(); // 다음에 배정할 사람 번호
	double best = 0;

	for (int job = 0; job < n; job++) {
		if (mask & (1 << job)) continue; // 이미 쓰인 직업은 건너뜀
		double cand = prob[person][job] * dfs(mask | (1 << job));
		if (cand > best) best = cand;
	}

	visited_[mask] = true;
	memo[mask] = best;
	return best;
}

int main() {
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cout << "#" << test_case << " ";
		cin >> n;
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++) {
				double k; cin >> k; k /= 100; prob[i][j] = k;
			}

		int full = (1 << n);
		for (int mask = 0; mask < full; mask++) visited_[mask] = false;

		double ans = dfs(0);

		cout << fixed; cout.precision(6);
		cout << ans * 100;
		cout << "\n";
	}
	return 0;
}
