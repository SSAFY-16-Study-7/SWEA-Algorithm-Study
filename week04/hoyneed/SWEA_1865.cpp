#include <algorithm>
// #include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
namespace {
int N;
vector<vector<int>> prob;
vector<double> memo;
double answer = 0.0;
} // namespace

void solve(int test_case);
void dfs(int depth, double percent, int visited);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  // (void)freopen("input.txt", "r", stdin);
  cin >> T;

  // double 출력을 소수점 아래 6자리(반올림)까지로 고정
  cout << fixed;
  cout.precision(6);

  for (int test_case = 1; test_case <= T; ++test_case) {
    answer = 0.0;
    solve(test_case);
  }
  return 0;
}

void solve(const int test_case) {
  cin >> N;
  prob.assign(N, vector<int>(N));
  for (auto &row : prob) {
    for (int &c : row) {
      cin >> c;
    }
  }
  // bit masking으로 모든 상태를 저장하고, 각 상태에 대한 방문 상태 기록
  memo.assign(1 << N, -1.0);
  dfs(0, 100.0, 0);
  cout << '#' << test_case << ' ' << answer << '\n';
}

// visited: 비트마스킹을 이용한 정수형 방문 확인
void dfs(const int depth, double percent, int visited) {
  // 현재 작업 상태에 더 좋은 확률이 있으면 가지치기
  if (memo[visited] >= percent)
    return;
  memo[visited] = percent;

  if (depth == N) {
    answer = max(answer, percent);
    return;
  }

  for (int i = 0; i < N; ++i) {
    // 해당 업무가 이미 할당되었는지 확인
    if ((visited & (1 << i)) || !prob[depth][i])
      continue;

    double next_prob = percent * prob[depth][i] / 100.0;

    // 현재 찾은 최대 확률보다 낮으면 스킵
    if (next_prob <= answer)
      continue;

    dfs(depth + 1, next_prob, visited | (1 << i));
  }
}