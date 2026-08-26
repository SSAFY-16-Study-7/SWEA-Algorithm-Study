#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <set>
#include <iomanip>

using namespace std;


int main() {
	int n;
	int T = 10;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		vector<int> arr(101);
		int max_value = 0;
		priority_queue<int, vector<int>, less<int>> max_pq;
		priority_queue<int, vector<int>, greater<int>> min_pq;
		for (int i = 0; i < 100; i++) {
			cin >> arr[i];
			max_pq.push(arr[i]);
			min_pq.push(arr[i]);
		}
		for (int i = 0; i < n; i++) {
			int max = max_pq.top();
			int min = min_pq.top();
			max_pq.pop();
			min_pq.pop();
			max_pq.push(max - 1);
			min_pq.push(min + 1);
		}
		int ans = max_pq.top() - min_pq.top();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}
