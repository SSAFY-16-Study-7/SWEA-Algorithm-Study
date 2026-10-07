#include <array>
#include <bitset>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
namespace {
constexpr int MAX_N = 501;
int N, M;
array<vector<int>, MAX_N> graph;
array<int, MAX_N> indegree;

}  // namespace

static void solve() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    graph[i].clear();
  }
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    ++indegree[v];
  }
  // 위상 정렬
  queue<int> q;
  for (int i = 0; i < N; i++) {
    if (!indegree[i]) q.push(i);
  }
  vector<int> order;
  order.reserve(N);
  while (!q.empty()) {
    const int cur = q.front();
    q.pop();
    order.push_back(cur);
    for (const int next : graph[cur]) {
      if (--indegree[next] == 0) {
        q.push(next);
      }
    }
  }
  vector<bitset<MAX_N>> taller(N + 1);
  vector<bitset<MAX_N>> smaller(N + 1);
  // taller DP (역위상순)
  for (int idx = N - 1; idx >= 0; idx--) {
    const int cur = order[idx];
    for (const int next : graph[cur]) {
      taller[cur].set(next);
      taller[cur] |= taller[next];
    }
  }
  // smaller DP (위상순)
  for (const int cur : order) {
    for (const int next : graph[cur]) {
      smaller[next].set(cur);
      smaller[next] |= smaller[cur];
    }
  }
  int answer = 0;

  for (int i = 1; i <= N; ++i) {
    // 확실하게 작은 학생과 확실하게 큰 학생의 합이 N-1이면 순서를 앎
    int known = (int)smaller[i].count() + (int)taller[i].count();

    if (known == N - 1) {
      ++answer;
    }
  }
  cout << answer << '\n';
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_case;
  int T;
  //(void)freopen("sample_input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    cout << '#' << test_case << ' ';
    solve();
  }
}