#include <array>
#include <climits>
// #include <cstdio>
#include <iostream>
#include <queue>
#include <string>

using namespace std;
namespace {
struct Node {
  int y, x, cost;
  Node(int y, int x, int c) : y(y), x(x), cost(c) {}
  // pq에서 cost가 적은 Node부터 나오도록 설정
  bool operator<(const Node& other) const {
    return cost > other.cost;
  }
};
array<int, 4> dy{-1, 0, 1, 0};
array<int, 4> dx{0, -1, 0, 1};
int N;
vector<vector<int>> map;
}  // namespace
void solve(int test_case);
int bfs();

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  int test_case;
  //  freopen("input.txt", "r", stdin);
  cin >> T;

  for (test_case = 1; test_case <= T; ++test_case) {
    solve(test_case);
  }
  return 0;
}

void solve(const int test_case) {
  cin >> N;
  map.assign(N, vector<int>(N));
  // string으로 받아서 int로 변환해 삽입
  for (auto& row : map) {
    string input;
    cin >> input;
    for (int i = 0; i < N; i++) {
      row[i] = int(input[i] - '0');
    }
  }
  cout << "#" << test_case << ' ' << bfs() << '\n';
}
int bfs() {
  vector<vector<int>> min_costs(N, vector<int>(N, INT_MAX));
  min_costs[0][0] = 0;
  priority_queue<Node> pq;
  pq.emplace(0, 0, 0);
  while (!pq.empty()) {
    Node cur = pq.top();
    pq.pop();
    if (cur.y == N - 1 && cur.x == N - 1) return cur.cost;
    for (int d = 0; d < 4; d++) {
      int ny = cur.y + dy[d];
      int nx = cur.x + dx[d];
      if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
      int nCost = cur.cost + map[ny][nx];
      // 해당 지역에 이미 더 낮은 비용으로 도착 가능하면 가지치기
      if (nCost >= min_costs[ny][nx]) continue;
      min_costs[ny][nx] = nCost;
      pq.emplace(ny, nx, nCost);
    }
  }
  return -1;
}