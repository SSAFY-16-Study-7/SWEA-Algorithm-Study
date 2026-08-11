#include <array>
// #include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
namespace {
array<array<bool, 101>, 101> graph{};
}  // namespace
void solve(int test_case);
int bfs(int start);

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_case;
  //  freopen("input.txt", "r", stdin);
  for (test_case = 1; test_case <= 10; ++test_case) {
    graph.fill({});
    solve(test_case);
  }
  return 0;
}

void solve(const int test_case) {
  int len, start;
  cin >> len >> start;
  for (int i = 0; i < (len / 2); i++) {
    int from, to;
    cin >> from >> to;
    graph[from][to] = true;
  }
  cout << "#" << test_case << ' ' << bfs(start) << '\n';
}

int bfs(const int start) {
  int answer = -1;
  int max_dist = -1;
  // 거리를 저장하는 배열로 방문 처리도 같이 기록
  array<int, 101> dists{};
  queue<int> qu;
  dists[start] = 1;
  qu.push(start);
  while (!qu.empty()) {
    int cur = qu.front();
    qu.pop();
    // 현재 최대 거리보다 멀거나, 같아도 번호가 큰 경우
    if (dists[cur] > max_dist || (dists[cur] == max_dist && cur > answer)) {
      answer = cur;
      max_dist = dists[cur];
    }
    for (int next = 1; next < 101; next++) {
      // 연결되지 않거나 이미 방문했으면 continue
      if (!graph[cur][next] || dists[next]) continue;
      dists[next] = dists[cur] + 1;
      qu.push(next);
    }
  }
  return answer;
}
