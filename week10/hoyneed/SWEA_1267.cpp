#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
namespace {
constexpr int MAX_V = 1001;
int V, E;
array<vector<int>, MAX_V> graph;
array<int, MAX_V> indegree;
queue<int> q;
} // namespace

static void solve() {
  cin >> V >> E;
  for (int i = 1; i <= V; ++i) {
    graph[i].clear();
    indegree[i] = 0;
  }
  q = {};
  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    ++indegree[v];
  }
  for (int i = 1; i <= V; ++i) {
    if (!indegree[i]) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    const int cur = q.front();
    q.pop();
    cout << cur << ' ';
    for (const int next : graph[cur]) {
      if (--indegree[next] == 0) {
        q.push(next);
      }
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 10;
  // (void)freopen("sample_input.txt", "r", stdin);
  for (int test_case = 1; test_case <= T; ++test_case) {
    cout << '#' << test_case << ' ';
    solve();
  }
}