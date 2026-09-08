#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        int N;
        cin >> N;

        int M = N * N;

        // pos[value] = {y, x}
        vector<pair<int, int>> pos(M + 1);

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {

                int value;
                cin >> value;

                pos[value] = { y, x };
            }
        }

        // dp[v] =
        // v번 방에서 출발했을 때 방문 가능한 방의 개수
        vector<int> dp(M + 1, 1);

        for (int v = M - 1; v >= 1; v--) {

            int y1 = pos[v].first;
            int x1 = pos[v].second;

            int y2 = pos[v + 1].first;
            int x2 = pos[v + 1].second;

            // v와 v+1이 상하좌우로 붙어있다면
            if (abs(y1 - y2) + abs(x1 - x2) == 1) {
                dp[v] = dp[v + 1] + 1;
            }
        }

        int bestRoom = 1;
        int bestCount = dp[1];

        for (int v = 2; v <= M; v++) {

            if (dp[v] > bestCount) {
                bestCount = dp[v];
                bestRoom = v;
            }
        }

        cout << "#" << tc << " "
             << bestRoom << " "
             << bestCount << '\n';
    }

    return 0;
}
