#include <array>
// #include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;
namespace {
array<int, 8> dy{-1, -1, -1, 0, 0, 1, 1, 1};
array<int, 8> dx{-1, 0, 1, -1, 1, -1, 0, 1};
int N;
vector<string> board;
vector<vector<short>> numBoard;
vector<vector<bool>> visited;
int answer = 0;
} // namespace

void solve(int test_case);
void bfs(int startY, int startX);

int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  // freopen("input.txt", "r", stdin);
  cin >> T;

  for (int test_case = 1; test_case <= T; ++test_case) {
    board.clear();
    solve(test_case);
  }
  return 0;
}

void solve(const int test_case) {
  cin >> N;
  if (board.capacity() < N)
    board.reserve(N);
  for (int i = 0; i < N; i++) {
    string input;
    cin >> input;
    board.push_back(input);
  }
  // 모든 칸이 다른 그룹일때 숫자부터 시작
  answer = N * N;
  // 숫자 보드를 미리 만들어놓기
  numBoard.assign(N, vector<short>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == '*') {
        // 지뢰는 그룹 수에서 제외
        answer--;
        numBoard[i][j] = -1;
        for (int d = 0; d < 8; d++) {
          int ny = i + dy[d];
          int nx = j + dx[d];
          if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            continue;
          if (board[ny][nx] == '*')
            continue;
          numBoard[ny][nx]++;
        }
      }
    }
  }
  visited.assign(N, vector<bool>(N, false));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // 클릭한 숫자가 0일때만 2개 이상의 숫자가 공개됨
      // 아직 방문하지 않았고 숫자가 0일때 bfs 시작
      if (!visited[i][j] && numBoard[i][j] == 0) {
        bfs(i, j);
      }
    }
  }
  cout << "#" << test_case << ' ' << answer << '\n';
}

void bfs(const int startY, const int startX) {
  visited[startY][startX] = true;
  queue<pair<int, int>> qu;
  qu.emplace(startY, startX);
  while (!qu.empty()) {
    const int y = qu.front().first;
    const int x = qu.front().second;
    qu.pop();
    // 현재 숫자가 0이 아니면 주변 공개 안함
    if (numBoard[y][x] != 0)
      continue;
    for (int d = 0; d < 8; d++) {
      const int ny = y + dy[d];
      const int nx = x + dx[d];
      if (ny < 0 || nx < 0 || ny >= N || nx >= N)
        continue;
      if (visited[ny][nx] || board[ny][nx] == '*')
        continue;
      // 그룹에 편입되면 정답에서 빼주기
      answer--;
      visited[ny][nx] = true;
      qu.emplace(ny, nx);
    }
  }
}