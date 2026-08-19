// #include <cstdio>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
namespace {
constexpr int DY[4]{-1, 0, 1, 0};
constexpr int DX[4]{0, -1, 0, 1};
char arr[4][4]{};
// unordered_set으로 최종 숫자 중복 방지
unordered_set<string> number_set;
} // namespace

void solve(int test_case);
int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_case;
  int T;
  // (void)freopen("input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    number_set.clear();
    solve(test_case);
  }
  return 0;
}

void dfs(int y, int x, string &number);

void solve(const int test_case) {
  for (auto &row : arr) {
    for (char &c : row) {
      cin >> c;
    }
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      string number{};
      number.reserve(7);
      number += arr[i][j];
      dfs(i, j, number);
    }
  }
  cout << '#' << test_case << ' ' << number_set.size() << '\n';
}
// 같은 곳을 다시 올 수 있으므로 방문 배열 사용 불가능.
void dfs(int y, int x, string &number) {
  if (number.length() == 7) {
    number_set.insert(number);
    return;
  }
  for (int d = 0; d < 4; ++d) {
    int ny = y + DY[d];
    int nx = x + DX[d];
    if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) {
      continue;
    }
    number += arr[ny][nx];
    dfs(ny, nx, number);
    // 백트레킹
    number.pop_back();
  }
}
