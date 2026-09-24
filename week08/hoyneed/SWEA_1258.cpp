#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
namespace {
constexpr int MAX_N = 100;
struct Container {
  int h, w, sz;
  Container() = default;
  Container(int h, int w) : h(h), w(w) { sz = h * w; }
  bool operator<(const Container& other) const {
    if (sz != other.sz) return sz < other.sz;
    return h < other.h;
  }
};
int N;
array<array<int, MAX_N>, MAX_N> grid;
array<array<bool, MAX_N>, MAX_N> visited;
vector<Container> containers;
void FindCont(const int y, const int x) {
  int y_end;
  for (y_end = y; y_end < N; y_end++) {
    if (grid[y_end][x] == 0) {
      --y_end;
      break;
    }
  }
  if (y_end == N) --y_end;
  int x_end;
  for (x_end = x; x_end < N; x_end++) {
    if (grid[y][x_end] == 0) {
      --x_end;
      break;
    }
  }
  for (int i = y; i <= y_end; i++) {
    for (int j = x; j <= x_end; j++) {
      visited[i][j] = true;
    }
  }
  if (x_end == N) --x_end;
  containers.emplace_back(y_end - y + 1, x_end - x + 1);
}
}  // namespace

static void solve() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    fill_n(visited[i].begin(), N, false);
    for (int j = 0; j < N; j++) {
      cin >> grid[i][j];
    }
  }
  containers.clear();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!grid[i][j] || visited[i][j]) continue;
      FindCont(i, j);
    }
  }
  sort(containers.begin(), containers.end());
  cout << containers.size() << ' ';
  for (const auto& con : containers) {
    cout << con.h << ' ' << con.w << ' ';
  }
  cout << '\n';
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_case;
  int T;
  //(void)freopen("sample_input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    cout << '#' << test_case << ' ';
    solve();
  }
}