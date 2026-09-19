#include <array>
#include <cmath>
#include <iostream>

using namespace std;
namespace {
constexpr int MAX_N = 1e5;
int N, H;
array<int, MAX_N> cars;
array<bool, MAX_N> lights;
} // namespace
static void solve() {
  cin >> N >> H;
  for (int i = 0; i < N; i++) {
    cin >> cars[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> lights[i];
  }
  long long curLen = 0;
  int answer = 0;

  if (!lights[0]) {
    lights[0] = true;
    ++answer;
  }
  if (!lights[N - 1]) {
    lights[N - 1] = true;
    ++answer;
  }
  for (int i = 0; i < N; ++i) {
    if (lights[i]) {
      curLen = 0;
      continue;
    }

    curLen += cars[i];

    if (curLen >= H) {
      ++answer;

      // 현재 i번 칸을 켠다고 선택
      curLen = 0;
    }
  }
  cout << answer << '\n';
}

int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  // (void)freopen("sample_input.txt", "r", stdin);
  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    cout << '#' << test_case << ' ';
    solve();
  }
}