#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;

int n;
double prob[16][16];
bool used[16];

vector<pair<double, int>> order[16];

double max_ans;

// row 이후의 직원들이 얻을 수 있는
// 이론상 최대 배율
double suffixMax[17];

void dfs(int row, double cur_prob) {

    // 현재 확률 자체가 이미 최고값보다 작음
    if (cur_prob <= max_ans)
        return;

    // 앞으로 전부 각 행의 최고 확률을 선택한다고 해도
    // 현재 최고 기록을 못 넘으면 종료
    if (cur_prob * suffixMax[row] <= max_ans)
        return;

    if (row == n) {
        max_ans = max(max_ans, cur_prob);
        return;
    }

    // 확률이 높은 일부터 탐색
    for (auto [p, col] : order[row]) {

        if (used[col])
            continue;

        if (p == 0)
            continue;

        used[col] = true;

        dfs(row + 1, cur_prob * p);

        used[col] = false;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        cin >> n;

        max_ans = 0;
        memset(used, false, sizeof(used));

        for (int i = 0; i < n; i++)
            order[i].clear();

        for (int row = 0; row < n; row++) {

            for (int col = 0; col < n; col++) {

                double x;
                cin >> x;

                prob[row][col] = x / 100.0;

                order[row].push_back({
                    prob[row][col],
                    col
                });
            }

            // 성공 확률 높은 순
            sort(
                order[row].begin(),
                order[row].end(),
                greater<pair<double, int>>()
            );
        }

        // suffixMax 계산
        suffixMax[n] = 1.0;

        for (int row = n - 1; row >= 0; row--) {

            double best = 0;

            for (int col = 0; col < n; col++)
                best = max(best, prob[row][col]);

            suffixMax[row]
                = suffixMax[row + 1] * best;
        }

        dfs(0, 1.0);

        cout << "#"
             << tc
             << " "
             << fixed
             << setprecision(6)
             << max_ans * 100.0
             << '\n';
    }

    return 0;
}
