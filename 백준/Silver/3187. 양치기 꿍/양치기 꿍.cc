// if (양의 숫자 > 늑대 숫자) 늑대가 잡아먹힘 
// 빈공간(.), 울타리(#), 늑대(v), 양(k)

#include <iostream>
#include <queue>

#define X first 
#define Y second

int ground[250][250];
bool vis[250][250];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int l_sheep, l_wolf, n_sheep, n_wolf; 

using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; 
    cin >> N >> M; 

    for (int i = 0; i < N; i++) {
        string input; 
        cin >> input; 
        for (int j = 0; j < M; j++) {
            ground[i][j] = input[j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ground[i][j] == '#' || ground[i][j] == '.') continue; 
            if (vis[i][j] == true) continue; 

            queue<pair<int, int>> Q; 
            Q.push({i, j});
            vis[i][j] = true; 
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                if (ground[cur.X][cur.Y] == 'k') n_sheep++;
                if (ground[cur.X][cur.Y] == 'v') n_wolf++;
                
                for(int dir = 0; dir < 4; dir++) {
                    int nxt_x = cur.X + dx[dir]; 
                    int nxt_y = cur.Y + dy[dir];
                    if (nxt_x < 0 || nxt_x >= N || nxt_y < 0 || nxt_y >= M) continue; 
                    if (vis[nxt_x][nxt_y] || ground[nxt_x][nxt_y] == '#') continue; 

                    Q.push({nxt_x, nxt_y});
                    vis[nxt_x][nxt_y] = true; 
                }
            }
            if (n_sheep > n_wolf) l_sheep += n_sheep;
            else l_wolf += n_wolf; 
            n_sheep = 0; n_wolf = 0; 
        }
    }

    cout << l_sheep << ' ' << l_wolf; 
    
    return 0;
}