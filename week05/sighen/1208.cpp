#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 10;

    for (int tc = 1; tc <= T; tc++) {
        int dump;
        cin >> dump;

        vector<int> v(100);

        for (int i = 0; i < 100; i++) {
            cin >> v[i];
        }

        while (dump--) {
            auto minmax = minmax_element(v.begin(), v.end());

            if (*minmax.second - *minmax.first <= 1)
                break;

            (*minmax.first)++;
            (*minmax.second)--;
        }

        auto minmax = minmax_element(v.begin(), v.end());

        cout << "#" << tc << " "
             << *minmax.second - *minmax.first << "\n";
    }

    return 0;
}
