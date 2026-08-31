#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        int n, m, k;
        cin >> n >> m >> k;

        vector<int> people(n);

        for (int i = 0; i < n; i++) {
            cin >> people[i];
        }

        sort(people.begin(), people.end());

        bool possible = true;

        for (int i = 0; i < n; i++) {

            int cur_time = people[i];

            // 현재 시간까지 만들어진 붕어빵 총개수
            int bread = (cur_time / m) * k;

            // i번째 손님까지 총 i+1명이 붕어빵을 먹어야 함
            if (bread < i + 1) {
                possible = false;
                break;
            }
        }

        cout << "#" << tc << " ";

        if (possible) {
            cout << "Possible\n";
        }
        else {
            cout << "Impossible\n";
        }
    }

    return 0;
}
