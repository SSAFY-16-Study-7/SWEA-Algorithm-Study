#include <array>
//#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
namespace {
constexpr array<int, 4> DY{-1, 0, 1, 0};
constexpr array<int, 4> DX{0, -1, 0, 1};
struct Point {
  int y, x;
  Point() = default;
  Point(int y, int x) : y(y), x(x) {}
};
struct Suyeon : Point {
  int distance;
  Suyeon() = default;
  Suyeon(int y, int x, int d) : Point(y, x), distance(d) {}
};
int H, W;
vector<vector<char>> map;
Point start;
Point goddess;
}  // namespace

void solve(int test_case);
int bfs(queue<Point>& demons);
void spread(queue<Point>& demons);

int main(int argc, char** argv) {
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
  cin >> H >> W;
  map.assign(H, vector<char>(W));
  queue<Point> demons;  // 악마의 손아귀 큐
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> map[i][j];
      if (map[i][j] == '*') {
        demons.emplace(i, j);
      } else if (map[i][j] == 'S') {
        start.y = i;
        start.x = j;
        map[i][j] = '.';
      } else if (map[i][j] == 'D') {
        goddess.y = i;
        goddess.x = j;
      }
    }
  }
  int answer = bfs(demons);
  cout << '#' << test_case << ' ';
  if (answer == -1)
    cout << "GAME OVER" << '\n';
  else
    cout << answer << '\n';
}

int bfs(queue<Point>& demons) {
  vector<vector<bool>> visited(H, vector<bool>(W));
  visited[start.y][start.x] = true;
  queue<Suyeon> qu;
  qu.emplace(start.y, start.x, 1);
  spread(demons);
  int level = 1;
  while (!qu.empty()) {
    Suyeon cur = qu.front();
    qu.pop();
    if (cur.distance > level) {
      level++;
      spread(demons);
    }
    for (int d = 0; d < 4; d++) {
      Suyeon next(cur.y + DY[d], cur.x + DX[d], cur.distance + 1);
      if (next.y < 0 || next.x < 0 || next.y >= H || next.x >= W) continue;
      if (map[next.y][next.x] == 'X' || map[next.y][next.x] == '*' ||
          visited[next.y][next.x])
        continue;
      // 1로 시작했으므로 도착했으면 1을 다시 빼줘야함
      if (next.y == goddess.y && next.x == goddess.x) return next.distance - 1;
      visited[next.y][next.x] = true;
      qu.push(next);
    }
  }
  return -1;
}

void spread(queue<Point>& demons) {
  // 맨 처음 큐에 들어있던 손아귀만 퍼짐
  const int sz = demons.size();
  for (int i = 0; i < sz; i++) {
    Point dm = demons.front();
    demons.pop();
    for (int d = 0; d < 4; d++) {
      Point next(dm.y + DY[d], dm.x + DX[d]);
      if (next.y < 0 || next.x < 0 || next.y >= H || next.x >= W) continue;
      if (map[next.y][next.x] == 'D' || map[next.y][next.x] == 'X' ||
          map[next.y][next.x] == '*')
        continue;
      map[next.y][next.x] = '*';
      demons.push(next);
    }
  }
}