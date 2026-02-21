// 문제: 섬의 개수 세기 
// 이동방향: 가로, 세로, 대각선 

#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1) {
        /* 맵의 크기 or 종료 코드 입력 받기 */
        int W, H;
        cin >> W >> H;
        if (W == 0 && H == 0) break; 

        /* map[][], vis[][] 초기화 */
        int map[50][50];
        int vis[50][50];
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                map[i][j] = 0;
                vis[i][j] = 0; 
            }
        }

        /* 지도 입력 받기: 1(Land) or 0(Sea) */
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                cin >> map[h][w];
            }
        }

        /* BFS: 섬의 개수 세기 */
        int count = 0;
        int dh[8] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dw[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if (!map[h][w] || vis[h][w]) continue;  // 바다이거나 이미 방문 시

                queue<pair<int, int>> Q;
                count++;
                Q.push({h, w});
                vis[h][w] = 1; 
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    
                    for (int dir = 0; dir < 8; dir++) {
                        int nxt_h = cur.X + dh[dir];
                        int nxt_w = cur.Y + dw[dir];
                        if (nxt_h < 0 || nxt_h >= H || nxt_w < 0 || nxt_w >= W) continue;
                        if (!map[nxt_h][nxt_w] || vis[nxt_h][nxt_w]) continue;

                        Q.push({nxt_h, nxt_w});
                        vis[nxt_h][nxt_w] = 1;
                    }
                }
            }
        }
        cout << count << '\n'; 
    }
    
    return 0;
}
