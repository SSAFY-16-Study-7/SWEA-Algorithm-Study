// #include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
namespace {
int N;
vector<bool> visited_col;
vector<bool> visited_LR; // 좌상->우하
vector<bool> visited_RL; // 우상->좌하
int answer = 0;
} // namespace
void solve(int test_case);
void dfs(int row);

int main(int argc, char **argv) {
  int test_case;
  int T;
  //(void)freopen("input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    answer = 0;
    solve(test_case);
  }
  return 0;
}

void solve(const int test_case) {
  cin >> N;
  visited_col.assign(N, false);
  visited_LR.assign(2 * N - 1, false); // 좌상->우하
  visited_RL.assign(2 * N - 1, false); // 우상->좌하
  dfs(0);

  cout << '#' << test_case << ' ' << answer << '\n';
}

void dfs(const int row) {
  if (row == N) {
    answer++;
    return;
  }
  for (int col = 0; col < N; col++) {
    if (visited_col[col] || visited_LR[row - col + N - 1] ||
        visited_RL[row + col])
      continue;
    visited_col[col] = true;
    visited_LR[row - col + N - 1] = true;
    visited_RL[row + col] = true;
    dfs(row + 1);
    // 백트레킹
    visited_col[col] = false;
    visited_LR[row - col + N - 1] = false;
    visited_RL[row + col] = false;
  }
}