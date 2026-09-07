#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
namespace {
int N, K;
int dp[1001];
}  // namespace

static void solve(const int test_case) {
  cin >> N >> K;

  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < N; i++) {
    int v, c;
    cin >> v >> c;
    for (int vol = K; vol >= v; vol--) {
      dp[vol] = max(dp[vol], dp[vol - v] + c);
    }
  }

  cout << '#' << test_case << ' ' << dp[K] << '\n';
}

int main(int argc, char** argv) {
  int test_case;
  int T;
  // (void)freopen("input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    solve(test_case);
  }
}