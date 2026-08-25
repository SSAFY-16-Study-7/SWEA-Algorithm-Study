#include <algorithm>
//#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
namespace {
int N, P;
struct Section {
  int st, ed;
  Section() = default;
  Section(int st, int ed) : st(st), ed(ed) {}
};
}  // namespace

static void solve(int test_case);

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_case;
  int T;
  //(void)freopen("input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    solve(test_case);
  }
  return 0;
}

void solve(const int test_case) {
  int n, p;
  cin >> n >> p;

  vector<int> days(n);
  for (int i = 0; i < n; ++i) {
    cin >> days[i];
  }

  int max_len = 0;
  int L = 0;

  //  R: 구간의 오른쪽 끝
  for (int R = 0; R < n; ++R) {
    // 구멍 일자의 수
    int needed = (days[R] - days[L] + 1) - (R - L + 1);

    // 구멍이 p 개수보다 넓으면 왼쪽 끝을 증가
    while (needed > p) {
      L++;
      needed = (days[R] - days[L] + 1) - (R - L + 1);
    }

    int current_len = (R - L + 1) + p;

    // 최댓값 갱신
    if (current_len > max_len) {
      max_len = current_len;
    }
  }

  cout << "#" << test_case << " " << max_len << "\n";
}