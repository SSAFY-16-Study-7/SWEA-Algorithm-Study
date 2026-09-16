#include <iostream>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int T, N;
string cmd;


void move(string cmd, vector<vector<int>>& arr) {
	if (cmd == "up") {
		for (int col = 0; col < N; col++) {
			queue<int> q; // 각 열마다 큐를 따로 관리
			int prev = arr[0][col]; // col열의 0번째 행
			int last_cur;
			for (int row = 1; row < N; row++) {
				int cur = arr[row][col];
				if (prev == 0) {
					prev = cur;
					if (row == N-1) { // 마지막 인덱스라면
						last_cur = cur;
					}
					continue; // 이전값이 0이면 그냥 pass하고 이전값을 cur로 갱신
				}
				if (cur != 0) {
					last_cur = cur;
				}
				if (cur == 0) {
					continue; // 0은 pass
				}
				if (prev == -1) { // 이전의 숫자가 합쳐졌을 경우
					prev = cur; // 이번 cur은 pass하고, prev가 됨. 다음 cur로 넘어감. 
					continue;
				}
				// 이전의 숫자가 합쳐진 숫자가 아닌 경우 (일반적인 경우)
				
				if (prev == cur) {
					q.push(prev + cur);
					prev = -1;
				}
				else {
					q.push(prev);
					prev = cur;
				}
			}
			// 찌꺼기 값이 남아 있을 수 있응므로 cur을 다시 한번 push.
			if (prev != -1) {
				q.push(prev);
			}
			// 해당 열/행에 대한 큐가 완성되었으면, 쌓아주면 됨.
			for (int i = 0; i < N; i++) {
				arr[i][col] = 0; // 해당 열의 모든 행을 0으로 초기화
			}
			int cnt = 0;
			while (!q.empty()) {
				int q_top = q.front();
				q.pop();
				arr[cnt][col] = q_top;
				cnt++; // 해당 칸을 채웠으므로, 다음 칸을 채울 차례.
			}
		}
	}
	else if (cmd == "down") {
		for (int col = 0; col < N; col++) {
			queue<int> q; // 각 열마다 큐를 따로 관리
			int prev = arr[N-1][col]; // col열의 0번째 행
			int last_cur;
			for (int row = N-2; row >= 0; row--) {
				int cur = arr[row][col];
				if (prev == 0) {
					prev = cur;
					if (row == 0) { // 마지막 인덱스라면
						last_cur = cur; 
					}
					continue; // 이전값이 0이면 그냥 pass하고 이전값을 cur로 갱신
				}
				if (cur != 0) {
					last_cur = cur;
				}
				if (cur == 0) {
					continue; // 0은 pass
				}
				if (prev == -1) { // 이전의 숫자가 합쳐졌을 경우
					prev = cur; // 이번 cur은 pass하고, prev가 됨. 다음 cur로 넘어감. 
					continue;
				}
				// 이전의 숫자가 합쳐진 숫자가 아닌 경우 (일반적인 경우)

				if (prev == cur) {
					q.push(prev + cur);
					prev = -1;
				}
				else {
					q.push(prev);
					prev = cur;
				}
			}
			// 찌꺼기 값이 남아 있을 수 있응므로 cur을 다시 한번 push.
			if (prev != -1) {
				q.push(prev);
			}
			// 해당 열/행에 대한 큐가 완성되었으면, 쌓아주면 됨.
			for (int i = 0; i < N; i++) {
				arr[i][col] = 0; // 해당 열의 모든 행을 0으로 초기화
			}
			int cnt = N-1;
			while (!q.empty()) {
				int q_top = q.front();
				q.pop();
				arr[cnt][col] = q_top;
				cnt--; // 해당 칸을 채웠으므로, 다음 칸을 채울 차례.
			}
		}
	}
	else if (cmd == "right") {
	for (int row = 0; row < N; row++) {
		queue<int> q; // 각 열마다 큐를 따로 관리
		int prev = arr[row][N - 1]; // col열의 0번째 행
		int last_cur;
		for (int col = N - 2; col >= 0; col--) {
			int cur = arr[row][col];
			if (prev == 0) {
				prev = cur;
				if (col == 0) { // 마지막 인덱스라면
					last_cur = cur;
				}
				continue; // 이전값이 0이면 그냥 pass하고 이전값을 cur로 갱신
			}
			if (cur != 0) {
				last_cur = cur;
			}
			if (cur == 0) {
				continue; // 0은 pass
			}
			if (prev == -1) { // 이전의 숫자가 합쳐졌을 경우
				prev = cur; // 이번 cur은 pass하고, prev가 됨. 다음 cur로 넘어감. 
				continue;
			}
			// 이전의 숫자가 합쳐진 숫자가 아닌 경우 (일반적인 경우)

			if (prev == cur) {
				q.push(prev + cur);
				prev = -1;
			}
			else {
				q.push(prev);
				prev = cur;
			}
		}
		// 찌꺼기 값이 남아 있을 수 있응므로 cur을 다시 한번 push.
		if (prev != -1) {
			q.push(prev);
		}
		// 해당 열/행에 대한 큐가 완성되었으면, 쌓아주면 됨.
		for (int i = 0; i < N; i++) {
			arr[row][i] = 0; // 해당 열의 모든 행을 0으로 초기화
		}
		int cnt = N - 1;
		while (!q.empty()) {
			int q_top = q.front();
			q.pop();
			arr[row][cnt] = q_top;
			cnt--; // 해당 칸을 채웠으므로, 다음 칸을 채울 차례.
		}
	}
	}
	else if (cmd == "left") {
	for (int row = 0; row < N; row++) {
		queue<int> q; // 각 열마다 큐를 따로 관리
		int prev = arr[row][0]; // col열의 0번째 행
		int last_cur;
		for (int col = 1; col < N; col++) {
			int cur = arr[row][col];
			if (prev == 0) {
				prev = cur;
				if (col == 0) { // 마지막 인덱스라면
					last_cur = cur;
				}
				continue; // 이전값이 0이면 그냥 pass하고 이전값을 cur로 갱신
			}
			if (cur != 0) {
				last_cur = cur;
			}
			if (cur == 0) {
				continue; // 0은 pass
			}
			if (prev == -1) { // 이전의 숫자가 합쳐졌을 경우
				prev = cur; // 이번 cur은 pass하고, prev가 됨. 다음 cur로 넘어감. 
				continue;
			}
			// 이전의 숫자가 합쳐진 숫자가 아닌 경우 (일반적인 경우)

			if (prev == cur) {
				q.push(prev + cur);
				prev = -1;
			}
			else {
				q.push(prev);
				prev = cur;
			}
		}
		// 찌꺼기 값이 남아 있을 수 있응므로 cur을 다시 한번 push.
		if (prev != -1) {
			q.push(prev);
		}
		// 해당 열/행에 대한 큐가 완성되었으면, 쌓아주면 됨.
		for (int i = 0; i < N; i++) {
			arr[row][i] = 0; // 해당 열의 모든 행을 0으로 초기화
		}
		int cnt = 0;
		while (!q.empty()) {
			int q_top = q.front();
			q.pop();
			arr[row][cnt] = q_top;
			cnt++; // 해당 칸을 채웠으므로, 다음 칸을 채울 차례.
		}
	}
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> cmd;
		vector<vector<int>> arr(N, vector<int>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		move(cmd, arr);
		cout << "#" << tc << "\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
	
	return 0;
}
