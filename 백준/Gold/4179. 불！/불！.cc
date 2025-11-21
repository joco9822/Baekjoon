#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[1002];
int dist_fire[1002][1002];   // 불의 전파 시간
int dist_jihoon[1002][1002]; // 지훈이의 이동 시간
int R, C;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    queue<pair<int,int>> Q_fire;
    queue<pair<int,int>> Q_jihoon;

    // 1. 입력 및 초기화
    for(int i = 0; i < R; i++){
        cin >> board[i];
        for(int j = 0; j < C; j++){
            // 거리 배열 -1로 초기화 (방문 안 함 처리)
            dist_fire[i][j] = -1;
            dist_jihoon[i][j] = -1;

            if(board[i][j] == 'F'){
                Q_fire.push({i, j});
                dist_fire[i][j] = 0;
            }
            if(board[i][j] == 'J'){
                Q_jihoon.push({i, j});
                dist_jihoon[i][j] = 0;
            }
        }
    }

    // 2. 불에 대한 BFS
    while(!Q_fire.empty()){
        auto cur = Q_fire.front();
        Q_fire.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(dist_fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;

            dist_fire[nx][ny] = dist_fire[cur.X][cur.Y] + 1;
            Q_fire.push({nx, ny});
        }
    }

    // 3. 지훈이에 대한 BFS
    while(!Q_jihoon.empty()){
        auto cur = Q_jihoon.front();
        Q_jihoon.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            // 범위 밖으로 나갔다는 것은 탈출 성공을 의미함
            if(nx < 0 || nx >= R || ny < 0 || ny >= C){
                cout << dist_jihoon[cur.X][cur.Y] + 1;
                return 0;
            }

            // 이미 방문했거나 벽인 경우 패스
            if(dist_jihoon[nx][ny] >= 0 || board[nx][ny] == '#') continue;

            // 핵심 조건: 불이 도달한 곳이고, 지훈이가 불보다 늦거나 동시에 도착하면 패스
            // (dist_fire[nx][ny] == -1 인 경우는 불이 아예 안 닿는 곳이므로 이동 가능)
            if(dist_fire[nx][ny] != -1 && dist_fire[nx][ny] <= dist_jihoon[cur.X][cur.Y] + 1){
                continue;
            }

            dist_jihoon[nx][ny] = dist_jihoon[cur.X][cur.Y] + 1;
            Q_jihoon.push({nx, ny});
        }
    }

    // 4. 큐가 빌 때까지 탈출 못하면 불가능
    cout << "IMPOSSIBLE";
    return 0;
}