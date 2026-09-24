#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace {
struct Cell {
  int num;
  bool merged;
  Cell() = default;
  Cell(int num, bool merged) : num(num), merged(merged) {}
};
int N;
string input;
vector<vector<int>> o_grid;
vector<vector<Cell>> n_grid;
}  // namespace

static void solve() {
  cin >> N >> input;
  o_grid.assign(N, vector<int>(N));
  n_grid.assign(N, vector<Cell>());
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> o_grid[i][j];
    }
  }
  if (input == "up") {
    for (int j = 0; j < N; j++) {
      for (int i = 0; i < N; i++) {
        if (o_grid[i][j] == 0) continue;
        if (n_grid[j].empty() || n_grid[j].back().merged == true ||
            n_grid[j].back().num != o_grid[i][j]) {
          n_grid[j].emplace_back(o_grid[i][j], false);
        } else {
          n_grid[j].back().num *= 2;
          n_grid[j].back().merged = true;
        }
      }
      while (n_grid[j].size() < N) {
        n_grid[j].emplace_back(0, false);
      }
    }
    for (int j = 0; j < N; j++) {
      for (int i = 0; i < N; i++) {
        cout << n_grid[i][j].num << ' ';
      }
      cout << '\n';
    }
  } else if (input == "down") {
    for (int j = 0; j < N; ++j) {
      for (int i = N - 1; i >= 0; --i) {
        if (o_grid[i][j] == 0) continue;
        if (n_grid[j].empty() || n_grid[j].back().merged == true ||
            n_grid[j].back().num != o_grid[i][j]) {
          n_grid[j].emplace_back(o_grid[i][j], false);
        } else {
          n_grid[j].back().num *= 2;
          n_grid[j].back().merged = true;
        }
      }
      while (n_grid[j].size() < N) {
        n_grid[j].emplace_back(0, false);
      }
    }
    for (int j = N - 1; j >= 0; --j) {
      for (int i = 0; i < N; ++i) {
        cout << n_grid[i][j].num << ' ';
      }
      cout << '\n';
    }
  } else if (input == "left") {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (o_grid[i][j] == 0) continue;
        if (n_grid[i].empty() || n_grid[i].back().merged == true ||
            n_grid[i].back().num != o_grid[i][j]) {
          n_grid[i].emplace_back(o_grid[i][j], false);
        } else {
          n_grid[i].back().num *= 2;
          n_grid[i].back().merged = true;
        }
      }
      while (n_grid[i].size() < N) {
        n_grid[i].emplace_back(0, false);
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cout << n_grid[i][j].num << ' ';
      }
      cout << '\n';
    }
  } else {
    for (int i = 0; i < N; i++) {
      for (int j = N - 1; j >= 0; --j) {
        if (o_grid[i][j] == 0) continue;
        if (n_grid[i].empty() || n_grid[i].back().merged == true ||
            n_grid[i].back().num != o_grid[i][j]) {
          n_grid[i].emplace_back(o_grid[i][j], false);
        } else {
          n_grid[i].back().num *= 2;
          n_grid[i].back().merged = true;
        }
      }
      while (n_grid[i].size() < N) {
        n_grid[i].emplace_back(0, false);
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = N - 1; j >= 0; --j) {
        cout << n_grid[i][j].num << ' ';
      }
      cout << '\n';
    }
  }
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_case;
  int T;
  //(void)freopen("sample_input.txt", "r", stdin);
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    cout << '#' << test_case << '\n';
    solve();
  }
}