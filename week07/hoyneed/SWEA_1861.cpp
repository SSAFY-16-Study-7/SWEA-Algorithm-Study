#include <algorithm>
#include <array>
#include <iostream>
#include <queue>

using namespace std;
namespace {
struct Room {
  int y, x;
  int num;
  Room() = default;
  Room(int y, int x, int num) : y(y), x(x), num(num) {}
  bool operator<(const Room& other) const { return num < other.num; }
};
constexpr int MAX_N = 1e3;
constexpr int DY[4]{-1, 0, 1, 0};
constexpr int DX[4]{0, -1, 0, 1};

int N;
array<array<int, MAX_N>, MAX_N> rooms;
array<array<int, MAX_N>, MAX_N> dp;
priority_queue<Room> pq;
}  // namespace

static void solve(const int test_case) {
  cin >> N;
  pq = {};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> rooms[i][j];
      dp[i][j] = 1;
      pq.emplace(i, j, rooms[i][j]);
    }
  }
  int ans_num = -1;
  int max_cnt = 0;
  while (!pq.empty()) {
    Room cur = pq.top();
    pq.pop();
    // 가장 작은 숫자가 답이므로 >= 로 처리
    if (dp[cur.y][cur.x] >= max_cnt) {
      max_cnt = dp[cur.y][cur.x];
      ans_num = cur.num;
    }
    for (int d = 0; d < 4; d++) {
      const int ny = cur.y + DY[d];
      const int nx = cur.x + DX[d];
      if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
      if (rooms[ny][nx] == cur.num - 1) {
        dp[ny][nx] = max(dp[ny][nx], dp[cur.y][cur.x] + 1);
      }
    }
  }
  cout << '#' << test_case << ' ' << ans_num << ' ' << max_cnt << '\n';
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_case;
  int T;
  //(void)freopen("sample_input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    solve(test_case);
  }
}