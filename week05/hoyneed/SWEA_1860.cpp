#include <algorithm>
//#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
namespace {
int N, M, K;
}

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
  cin >> N >> M >> K;
  vector<int> arrival(N);
  for (auto& c : arrival) {
    cin >> c;
  }
  // 도착 시간 오름차순 정렬
  sort(arrival.begin(), arrival.end());
  int stock = 0;
  int time = 0;
  cout << "#" << test_case << ' ';
  for (int order = 0; order < N; order++) {
    // 두 시간 사이에 붕어빵 완성 시간이 있었는지 확인해서 stock에 더해줌
    int gap = arrival[order] / M - time / M;
    stock += K * gap;
    time = arrival[order];
    stock--;
    if (stock < 0) {
      cout << "Impossible\n";
      return;
    }
  }
  cout << "Possible\n";
}
