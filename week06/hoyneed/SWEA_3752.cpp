#include <bitset>
#include <iostream>

using namespace std;
namespace {
int N;
bitset<10'001> poss_scores;
} // namespace

static void solve(const int test_case) {
  poss_scores.reset();
  poss_scores.set(0);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int score;
    cin >> score;
    poss_scores |= (poss_scores << score);
  }
  cout << '#' << test_case << ' ' << poss_scores.count() << '\n';
}

int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_case;
  int T;
  (void)freopen("input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    solve(test_case);
  }
  return 0;
}
