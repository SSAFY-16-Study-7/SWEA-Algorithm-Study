#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
//#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
namespace {
struct Point {
  int x, y;
  Point() = default;
  Point(int x, int y) : x(x), y(y) {}
};
struct State {
  int node, distance, visited, depth;
  State() = default;
  State(int node, int distance, int depth, int visited)
      : depth(depth), distance(distance), visited(visited), node(node) {}

  bool operator<(const State& other) const {
    if (distance != other.distance) return distance > other.distance;
    return depth < other.depth;
  }
};
int N;
Point start{};
Point dest{};
vector<Point> customers;
array<array<int, 12>, 11> graph{};
int answer = INT_MAX;
}  // namespace

void solve(int test_case);
void dfs(int node, int depth, int visited, int dist);
void init();

int main(int argc, char** argv) {
  int test_case;
  int T;
  //(void)freopen("input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    init();
    solve(test_case);
  }
  return 0;
}

void solve(const int test_case) {
  cin >> N;
  cin >> start.x >> start.y;
  cin >> dest.x >> dest.y;
  customers.reserve(N);
  for (int i = 1; i <= N; i++) {
    int x, y;
    cin >> x >> y;
    customers.emplace_back(x, y);
    // 출발점/목적지로부터 고객 위치까지의 거리 측정
    graph[0][i] = abs(x - start.x) + abs(y - start.y);
    graph[i][11] = abs(x - dest.x) + abs(y - dest.y);
  }
  // 고객 집끼리의 거리 특정
  for (int i = 0; i < N - 1; i++) {
    Point from = customers[i];
    for (int j = i + 1; j < N; j++) {
      Point to = customers[j];
      int dist = abs(from.x - to.x) + abs(from.y - to.y);
      graph[i + 1][j + 1] = dist;
      graph[j + 1][i + 1] = dist;
    }
  }
  // dfs를 통해 탐색
  for (int i = 1; i <= N; i++) {
    int next_visited = (1 << i) | 1;
    dfs(i, 1, next_visited, graph[0][i]);
  }

  cout << '#' << test_case << ' ' << answer << '\n';
}

void dfs(const int node, const int depth, const int visited, const int dist) {
  if (dist > answer) return;
  // 고객을 모두 방문했으면 목적지까지의 거리를 더해서 정답 업데이트
  if (depth == N) {
    answer = min(answer, dist + graph[node][11]);
    return;
  }
  for (int i = 1; i <= N; i++) {
    if (visited & (1 << i)) continue;
    dfs(i, depth + 1, visited | (1 << i), dist + graph[node][i]);
  }
}

void init() {
  answer = INT_MAX;
  customers.clear();
  for (auto& row : graph) {
    row.fill(0);
  }
}