#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;

        vector<int> lis;

        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;

            // x 이상인 첫 번째 위치를 찾는다.
            auto it = lower_bound(lis.begin(), lis.end(), x);

            if (it == lis.end()) {
                // x가 현재 모든 값보다 크다면 뒤에 추가
                lis.push_back(x);
            }
            else {
                // 아니라면 해당 위치의 값을 x로 교체
                *it = x;
            }
        }

        cout << "#" << tc << " " << lis.size() << "\n";
    }

    return 0;
}
