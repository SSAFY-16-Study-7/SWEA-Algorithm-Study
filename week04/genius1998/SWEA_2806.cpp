#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
int n;
set<int> cols;
set<int> rx; // 대각선1
set<int> tx; // 대각선2
int cnt = 0;
void dfs(int row) { // 각 row에서 n개의 col을 순회하면서 두었다고 가정
	if (row == n) {
		cnt++;
		return; // n행은 없으므로 종료
	}
	for (int col = 0; col < n; col++) {
		if (!cols.count(col) && !rx.count(col-row) && !tx.count(col+row)) {
			cols.insert(col);
			rx.insert(col-row);
			tx.insert(col+row);

			dfs(row + 1);

			cols.erase(col);
			rx.erase(col - row);
			tx.erase(col + row);
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cnt = 0;
		cin >> n;
		dfs(0);
		cout << "#" << i << " " << cnt << "\n";
	}

	return 0;
}
