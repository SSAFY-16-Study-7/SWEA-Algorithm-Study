#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
namespace {
constexpr int MAX_N = 200'001;
using LL = long long;
struct Edge {
  int to;
  LL cost;
  Edge() = default;
  Edge(int to, LL cost) : to(to), cost(cost) {}
  bool operator<(const Edge &other) const { return cost > other.cost; }
};
int N, M;
array<vector<Edge>, MAX_N> graph;
array<LL, MAX_N> dist;
array<int, MAX_N> min_par_w;
priority_queue<Edge> pq;
} // namespace

static void solve() {
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    graph[i].clear();
  }
  fill_n(dist.begin(), N + 1, LLONG_MAX);
  fill_n(min_par_w.begin(), N + 1, INT_MAX);
  pq = {};
  for (int i = 0; i < M; ++i) {
    int p, q, cost;
    cin >> p >> q >> cost;
    graph[p].emplace_back(q, cost);
    graph[q].emplace_back(p, cost);
  }
  // 다익스트라
  dist[1] = 0;
  min_par_w[1] = 0;
  pq.emplace(1, 0);
  while (!pq.empty()) {
    auto [cur, cost] = pq.top();
    pq.pop();
    if (dist[cur] != cost)
      continue;
    for (auto [next, ec] : graph[cur]) {
      const LL nc = cost + ec;
      if (nc < dist[next]) {
        dist[next] = nc;
        // 잠재적 부모 후보
        min_par_w[next] = (int)ec;

        pq.emplace(next, nc);
      } else if (nc == dist[next]) {
        // 같은 최단거리를 만드는 다른 부모
        min_par_w[next] = min(min_par_w[next], (int)ec);
      }
    }
  }
  LL answer = 0;
  for (int i = 2; i <= N; ++i) {
    answer += min_par_w[i];
  }
  cout << answer << '\n';
}

int main(int argc, char **argv) {
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