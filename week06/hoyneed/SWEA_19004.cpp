#include <array>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
namespace {
struct Point {
  int y, x;
  Point() = default;
  Point(int y, int x) : y(y), x(x) {}
};
int N, K;
array<array<int, 50>, 50> map;
array<vector<Point>, 2502> points;
array<array<int, 50>, 50> dp;

int FindDist(const Point &a, const Point &b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}
} // namespace

static void solve(const int test_case) {
  cin >> N >> K;
  for (int i = 1; i <= K; ++i) {
    points[i].clear();
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> map[i][j];
      points[map[i][j]].emplace_back(i, j);
      if (map[i][j] == 1) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = INT_MAX;
      }
    }
  }
  if (K == 1) {
    cout << '#' << test_case << ' ';
    if (!points[1].empty()) {
      cout << 0 << '\n';
    } else {
      cout << -1 << '\n';
    }
    return;
  }
  int answer = INT_MAX;
  for (int i = 2; i <= K; ++i) {
    if (points[i].empty() || points[i - 1].empty())
      break;
    for (const auto &cur : points[i]) {
      for (const auto &prev : points[i - 1]) {
        dp[cur.y][cur.x] =
            min(dp[cur.y][cur.x], FindDist(prev, cur) + dp[prev.y][prev.x]);
      }
      if (i == K) {
        answer = min(answer, dp[cur.y][cur.x]);
      }
    }
  }
  if (answer == INT_MAX)
    answer = -1;
  cout << '#' << test_case << ' ' << answer << '\n';
}
int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_case;
  int T;
  // (void)freopen("input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    solve(test_case);
  }
}