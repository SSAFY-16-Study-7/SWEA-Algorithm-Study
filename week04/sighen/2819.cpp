#include<iostream>
#include<algorithm>
#include <unordered_set>
using namespace std;

int n;
char map[4][4];
unordered_set<string> num_set;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
string temp;


void dfs(int x, int y, int cur) {
	if (cur == 6) {
		num_set.insert(temp);
		return;
	}

	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
		temp[cur + 1] = map[nx][ny];
		dfs(nx, ny, cur + 1);
	}

}

int main() {
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cout << "#" << test_case << " ";
		num_set.clear();
		temp.resize(7);
		for (int i = 0;i < 4;i++) {
			for (int j = 0; j < 4;j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0;i < 4;i++) {
			for (int j = 0; j < 4;j++) {
				temp[0] = map[i][j];
				dfs(i, j, 0);
			}
		}

		cout << num_set.size() << "\n";
	}
	return 0;
}
