#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[100];

int main() {

	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cout << "#" << test_case << " ";
		
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 0;i < n;i++) {
			cin >> arr[i];
		}

		sort(arr, arr + n);

		bool possible = true;

		for (int i = 0; i < n; i++) {
			int bread = (arr[i] / m) * k;

			if (bread < i + 1) {
				possible = false;
				break;
			}
		}

		if (possible) cout << "Possible\n";
		else cout << "Impossible\n";

	}
	return 0;
}
