#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[50][52][52] = {0};
int vis[50][52][52] = {0};
int N[50] = {0};
int M[50] = {0};
int K[50] = {0};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++) {
        cin >> M[t] >> N[t] >> K[t]; 
        
        for(int k = 0; k < K[t]; k++) {
            int x, y;
            cin >> x >> y;
            board[t][y][x] = 1; 
        }
    }

    for(int t = 0; t < T; t++) {

        int area = 0; 

        for(int i = 0; i < N[t]; i++) {
            for(int j = 0; j < M[t]; j++) {

                if(board[t][i][j] == 0 || vis[t][i][j]) continue;

                area++;
                queue<pair<int, int>> Q;
                Q.push({i, j});
                vis[t][i][j] = 1;

                while(!Q.empty()) {
                    pair<int, int> cur = Q.front(); 
                    Q.pop();
                    
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        
                        if(nx < 0 || nx >= N[t] || ny < 0 || ny >= M[t]) continue;
                        
                        if(vis[t][nx][ny] || board[t][nx][ny] != 1) continue;
                        
                        vis[t][nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        cout << area << '\n';
    }

    return 0;
}