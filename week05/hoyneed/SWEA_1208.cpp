#include <algorithm>
#include <array>
//#include <cstdio>
#include <iostream>

using namespace std;
namespace {
int dumps;
array<int, 100> boxes;
}  // namespace

static void solve(int test_case);

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_case;
  int T = 10;
  //(void)freopen("input.txt", "r", stdin);
  for (test_case = 1; test_case <= T; ++test_case) {
    solve(test_case);
  }
  return 0;
}

void solve(const int test_case) {
  cin >> dumps;
  for (int i = 0; i < 100; i++) {
    cin >> boxes[i];
  }
  cout << '#' << test_case << ' ';
  for (int tries = 0; tries < dumps; tries++) {
    auto minmax = minmax_element(boxes.begin(), boxes.end());
    if (*minmax.second - *minmax.first <= 1) {
      cout << *minmax.second - *minmax.first << '\n';
      return;
    }
    (*minmax.first)++;
    (*minmax.second)--;
  }
  const auto minmax = minmax_element(boxes.begin(), boxes.end());
  cout << *minmax.second - *minmax.first << '\n';
}
