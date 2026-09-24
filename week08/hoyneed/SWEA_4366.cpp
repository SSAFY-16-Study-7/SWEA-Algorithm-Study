#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
namespace {
constexpr long long INF = LLONG_MAX;
string bin;
string thr;
unordered_set<long long> cand;
}  // namespace

static void solve() {
  cin >> bin >> thr;
  cand.clear();
  cand.reserve(bin.length());
  long long max_num = -1;
  for (auto& dig : bin) {
    const char temp = dig;
    if (dig == '0') {
      dig = '1';
    } else {
      dig = '0';
    }
    long long num = stoll(bin, nullptr, 2);
    max_num = max(max_num, num);
    cand.insert(num);
    dig = temp;
  }

  long long answer;
  for (auto& dig : thr) {
    const char temp = dig;
    if (dig == '0') {
      dig = '1';
      answer = stoll(thr, nullptr, 3);
      if (answer > max_num) continue;
      if (cand.count(answer) == 1) {
        break;
      }
      dig = '2';
      answer = stoll(thr, nullptr, 3);
      if (cand.count(answer) == 1) {
        break;
      }
    } else if (dig == '1') {
      dig = '0';
      answer = stoll(thr, nullptr, 3);
      if (cand.count(answer) == 1) {
        break;
      }
      dig = '2';
      answer = stoll(thr, nullptr, 3);
      if (cand.count(answer) == 1) {
        break;
      }
    } else if (dig == '2') {
      dig = '0';
      answer = stoll(thr, nullptr, 3);
      if (cand.count(answer) == 1) {
        break;
      }
      dig = '1';
      answer = stoll(thr, nullptr, 3);
      if (cand.count(answer) == 1) {
        break;
      }
    }
    dig = temp;
  }
  cout << answer << '\n';
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  //(void)freopen("sample_input.txt", "r", stdin);
  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    cout << '#' << test_case << ' ';
    solve();
  }
}
