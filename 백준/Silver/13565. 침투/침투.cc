#include <iostream>
#include <queue> 

#define X first
#define Y second 

using namespace std; 

int graph[1000][1000];  // 0은 전류 통함, 1은 전류 안통함
int vis[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; 
    cin >> N >> M; 
    
    for (int n = 0; n < N; n++) {
        string input; 
        cin >> input; 
        for (int m = 0; m < M; m++) {
            input[m] = input[m] - '0';
            graph[n][m] = input[m];
        }
    }

    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    queue<pair<int, int>> Q;
    for (int y = 0; y < M; y++) {
        if (graph[N-1][y] || vis[N-1][y]) continue; 
        vis[N-1][y] = 1; 
        Q.push({N-1, y}); 

        /* BFS */ 
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop(); 
    
            if (cur.X == 0) {
                cout << "YES"; 
                return 0; 
            }

            for(int i = 0; i < 4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M ) continue; 
                if (vis[nx][ny] || graph[nx][ny]) continue; 
                vis[nx][ny] = 1; 
                Q.push({nx, ny});
                // cout << nx << '\n';
            }
        }
    }

    cout << "NO";

    return 0;
}