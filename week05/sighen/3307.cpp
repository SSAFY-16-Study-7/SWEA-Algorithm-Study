#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {
	
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cout << "#" << test_case << " ";
		vector<int> v;
		vector<int> dp(1000, 0);
		int n;
		cin >> n;
		for (int i = 0; i < n;i++) {
			int t;
			cin >> t;
			v.push_back(t);
		}

		for (int i = 0; i < n;i++) {
			if (dp[i] == 0) {
				dp[i] = 1;
			}
			for (int j = 0; j < i; j++) {
				if (v[j] < v[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}

		cout << *max_element(dp.begin(), dp.end()) << "\n";


	}
	return 0;  
}
