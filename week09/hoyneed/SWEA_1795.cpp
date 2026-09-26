#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
namespace {
constexpr int MAX_N = 1001;
constexpr int INF = INT_MAX / 2 - 1;
// {cost, to}
using Edge = pair<int, int>;
int N, M, X;
array<vector<Edge>, MAX_N> graph;
array<vector<Edge>, MAX_N> reverse_graph;
array<int, MAX_N> f_dist;
array<int, MAX_N> r_dist;
priority_queue<Edge, vector<Edge>, greater<>> pq;
void Dij_f() {
  fill_n(f_dist.begin(), N + 1, INF);
  pq = {};
  f_dist[X] = 0;
  pq.emplace(0, X);
  while (!pq.empty()) {
    const auto [total, cur] = pq.top();
    pq.pop();
    if (total != f_dist[cur])
      continue;
    for (auto [ec, next] : graph[cur]) {
      const int next_total = total + ec;
      if (f_dist[next] <= next_total)
        continue;
      f_dist[next] = next_total;
      pq.emplace(next_total, next);
    }
  }
}
void Dij_r() {
  fill_n(r_dist.begin(), N + 1, INF);
  pq = {};
  r_dist[X] = 0;
  pq.emplace(0, X);
  while (!pq.empty()) {
    const auto [total, cur] = pq.top();
    pq.pop();
    if (total != r_dist[cur])
      continue;
    for (auto [ec, next] : reverse_graph[cur]) {
      const int next_total = total + ec;
      if (r_dist[next] <= next_total)
        continue;
      r_dist[next] = next_total;
      pq.emplace(next_total, next);
    }
  }
}

} // namespace

static void solve() {
  cin >> N >> M >> X;
  for (int i = 1; i <= N; ++i) {
    graph[i].clear();
    reverse_graph[i].clear();
  }
  for (int i = 0; i < M; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    graph[u].emplace_back(c, v);
    reverse_graph[v].emplace_back(c, u);
  }
  Dij_f();
  Dij_r();
  int answer = -1;
  for (int i = 1; i <= N; ++i) {
    answer = max(answer, f_dist[i] + r_dist[i]);
  }
  cout << answer << '\n';
}

int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  (void)freopen("sample_input.txt", "r", stdin);
  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    cout << '#' << test_case << ' ';
    solve();
  }
}