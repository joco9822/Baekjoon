#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second 

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str[102] ;
	int vis[102][102] = { 0 };

	int N;
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> str[n]; 
	}
	for (int i = 0; i < N; i++) fill(vis[i], vis[i] + N, 0);
	
	queue<pair<int, int>> Q;
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	// 빨간색 
	int red = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j] || str[i][j] != 'R') continue;
			Q.push({ i, j });
			vis[i][j] = 1;
			red++; 
			while (!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (vis[nx][ny] || str[nx][ny] != 'R') continue;
					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
		}
	}
	// 파란색 
	int blue = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j] || str[i][j] != 'B') continue;
			Q.push({ i, j });
			vis[i][j] = 1;
			blue++;
			while (!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (vis[nx][ny] || str[nx][ny] != 'B') continue;
					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
		}
	}

	// 초록색 
	int green = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j] || str[i][j] != 'G') continue;
			Q.push({ i, j });
			vis[i][j] = 1; 

			green++;
			while (!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (vis[nx][ny] || str[nx][ny] != 'G') continue;
					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
		}
	}

	cout << red + green + blue << ' ';

	for (int i = 0; i < N; i++) fill(vis[i], vis[i] + N, 0);

	int rg = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vis[i][j] || str[i][j] == 'B') continue;
			Q.push({ i, j });
			vis[i][j] = 1;
			rg++;
			while (!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (vis[nx][ny] || str[nx][ny] == 'B') continue;
					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
		}
	}
	cout << rg + blue;


	return 0;
}