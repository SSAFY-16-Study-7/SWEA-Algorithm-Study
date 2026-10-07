#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;
namespace {
constexpr int DY[4]{-1, 0, 1, 0};
constexpr int DX[4]{0, -1, 0, 1};
constexpr int MAX_N = 8;
struct Point {
  int y, x;
  Point() = default;
  Point(int y, int x) : y(y), x(x) {}
  bool operator==(const Point& other) const {
    return y == other.y && x == other.x;
  }
};
int N, K;
array<array<int, MAX_N>, MAX_N> grid;
vector<Point> highest;
int answer;

struct HashPoint {
  size_t operator()(const Point& p) const { return 1ULL * (p.y * MAX_N + p.x); }
};
unordered_map<Point, int, HashPoint> candidates;
Point lowered;

void bfs(const int y, const int x, const bool is_first) {
  queue<Point> qu;
  qu.emplace(y, x);
  int len = 0;
  int rem = 1;
  while (!qu.empty()) {
    const Point cur = qu.front();
    qu.pop();
    for (int d = 0; d < 4; d++) {
      const int ny = cur.y + DY[d];
      const int nx = cur.x + DX[d];
      if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
      if (grid[ny][nx] < grid[cur.y][cur.x]) {
        qu.emplace(ny, nx);
      } else {
        // K를 깎았을 때 다음 경로로 선택될 수 있으면 candidate에 넣음
        if (is_first && grid[ny][nx] - K < grid[cur.y][cur.x]) {
          const auto it = candidates.find(Point{ny, nx});
          if (it == candidates.end()) {
            candidates[Point{ny, nx}] = grid[ny][nx] - grid[cur.y][cur.x] + 1;
          } else {
            // 이미 깎을 예정이 있는 경우 더 낮은 것을 선택해서 경우의 수를 넓힘
            it->second = min(it->second, grid[ny][nx] - grid[cur.y][cur.x] + 1);
          }
        }
      }
    }
    if (--rem == 0) {
      rem = qu.size();
      answer = max(answer, ++len);
    }
  }
}
}  // namespace

static void solve() {
  cin >> N >> K;
  highest.clear();
  candidates.clear();
  int max_h = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> grid[i][j];
      if (grid[i][j] > max_h) {
        max_h = grid[i][j];
        highest = {Point{i, j}};
      } else if (grid[i][j] == max_h) {
        highest.emplace_back(i, j);
      }
    }
  }
  answer = 0;
  for (const auto& p : highest) {
    bfs(p.y, p.x, true);
  }
  for (const auto& can : candidates) {
    const Point& target = can.first;
    for (int cut = can.second; cut <= K; cut++) {
      if (grid[target.y][target.x] < cut) break;
      grid[target.y][target.x] -= cut;
      for (const auto& p : highest) {
        bfs(p.y, p.x, false);
      }
      grid[target.y][target.x] += cut;
    }
  }
  cout << answer << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;

  //(void)freopen("sample_input.txt", "r", stdin);
  cin >> T;
  for (int test_case = 1; test_case <= T; test_case++) {
    cout << '#' << test_case << ' ';
    solve();
  }
}