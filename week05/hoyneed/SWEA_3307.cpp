#include <algorithm>
#include <climits>
// #include <cstdio>
#include <iostream>

using namespace std;
namespace {
int N;
int answer;
int numbers[1001];
int dp[1001];
}  // namespace

void solve(int test_case);

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_case;
  int T;
 // (void)freopen("sample_input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    answer = -1;
    solve(test_case);
  }
  return 0;
}

void solve(const int test_case) {
  cin >> N;
  fill_n(dp, N, 1);
  for (size_t i = 0; i < N; i++) {
    cin >> numbers[i];
  }
  // dp를 활용해서 최대 수열 길이 구하기
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (numbers[i] <= numbers[j]) {
        dp[j] = max(dp[j], dp[i] + 1);
        answer = max(answer, dp[j]);
      }
    }
  }

  cout << '#' << test_case << ' ' << answer << '\n';
}