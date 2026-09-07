#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
namespace {
constexpr int MAX_N = 100'000;
int N;
array<int, MAX_N> numbers;
vector<int> dp;
}  // namespace

static void solve(const int test_case) {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> numbers[i];
  }
  for (int i = 0; i < N; i++) {
    const auto it = upper_bound(dp.begin(), dp.end(), numbers[i]);
    if (it == dp.end()) {
      dp.push_back(numbers[i]);
    } else {
      *it = numbers[i];
    }
  }

  cout << '#' << test_case << ' ' << dp.size() << '\n';
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
    dp.clear();
  }
}