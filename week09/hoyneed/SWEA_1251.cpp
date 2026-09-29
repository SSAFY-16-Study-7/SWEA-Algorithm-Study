#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;
namespace {
using LL = long long;
constexpr int MAX_N = 1000;
struct Point {
  int y, x;
};
struct State {
  int node;
  LL cost;
  State() = default;
  State(int node, LL cost) : node(node), cost(cost) {}
  bool operator<(const State &other) const { return cost > other.cost; }
};
int N;
array<Point, MAX_N> isles;
array<LL, MAX_N> min_edge;
array<bool, MAX_N> visited;
priority_queue<State> pq;
} // namespace

static void solve() {
  cin >> N;
  fill_n(min_edge.begin(), N, LLONG_MAX);
  fill_n(visited.begin(), N, false);
  pq = {};
  for (int i = 0; i < N; ++i) {
    cin >> isles[i].x;
  }
  for (int i = 0; i < N; ++i) {
    cin >> isles[i].y;
  }
  double perc;
  cin >> perc;
  min_edge[0] = 0;
  pq.emplace(0, 0);
  LL min_cost = 0;
  while (!pq.empty()) {
    const auto [node, cost] = pq.top();
    pq.pop();
    if (visited[node])
      continue;
    visited[node] = true;
    min_cost += cost;
    const Point cur = isles[node];
    for (int next = 1; next < N; ++next) {
      if (visited[next])
        continue;
      const Point nn = isles[next];
      const LL ec = 1LL * (nn.y - cur.y) * (nn.y - cur.y) +
                    1LL * (nn.x - cur.x) * (nn.x - cur.x);
      if (min_edge[next] <= ec)
        continue;
      min_edge[next] = ec;
      pq.emplace(next, ec);
    }
  }
  cout << llroundl((long double)min_cost * perc) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  // (void)freopen("sample_input.txt", "r", stdin);
  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    cout << '#' << test_case << ' ';
    solve();
  }
}