#include <array>
#include <iostream>
#include <string>

using namespace std;
namespace {
constexpr int MAX_N = 10'001;
constexpr long long DIV = 1'000'000'007;
string input;
int N;

array<int, MAX_N> inCharge;
array<array<long long, 16>, MAX_N> dp;
}  // namespace

static void solve(const int test_case) {
  cin >> input;
  N = (int)input.length();
  for (int i = 0; i < N; i++) {
    inCharge[i] = int(input[i] - 'A');
  }
  dp[0].fill(0);
  for (int visits = 1; visits < 16; visits++) {
    // 첫날 A는 반드시 포함돼야 함
    if (!(visits & 1)) continue;
    // 첫날 담당자도 포함돼야 함
    if (visits & 1 << inCharge[0]) {
      ++dp[0][visits];
    }
  }

  for (int day = 1; day < N; day++) {
    dp[day].fill(0);
    for (int visits = 1; visits < 16; visits++) {
      // 오늘 담당자가 포함돼야 함
      if (!(visits & 1 << inCharge[day])) continue;
      // 이전 날의 경우의 수를 순회하면서 붙어있는게 가능한 경우만 더함
      for (int prev = 1; prev < 16; prev++) {
        // 어제와 겹치는 인원이 하나도 없으면 불가능
        if (!(visits & prev)) continue;
        // 중간 과정에도 overflow가 일어날 수 있으므로 DIV로 나눠줌
        dp[day][visits] = (dp[day][visits] + dp[day - 1][prev]) % DIV;
      }
    }
  }
  long long answer = 0;
  for (int i = 1; i < 16; i++) {
    answer = (answer + dp[N - 1][i]) % DIV;
  }
  cout << '#' << test_case << ' ' << answer << '\n';
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_case;
  int T;
  //(void)freopen("sample_input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    solve(test_case);
  }
}