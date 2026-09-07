#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;
namespace {
constexpr int S = 200'001;
int N, B;
bitset<S> dp;
}  // namespace

static void solve(const int test_case) {
  cin >> N >> B;
  dp.set(0);
  // bitset을 h만큼 left shift하고 원본과 bitwise OR 연산 반복
  for (int i = 0; i < N; i++) {
    int h;
    cin >> h;
    dp |= (dp << h);
  }
  int answer = 0;
  for (int h = B; h < S; h++) {
    if (dp[h]) {
      answer = h - B;
      break;
    }
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
    dp.reset();
  }
}