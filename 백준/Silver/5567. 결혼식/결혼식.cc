// 입력: N = 학번(동기 수), M = 친구 관계 리스트 수 
// 출력: 결혼식에 초대하는 동기 수 
// 문제: 상근이는 자신의 친구와 친구의 친구를 초대 

#include <iostream>
#include <queue>
#include <vector> 

#define S first
#define C second

using namespace std; 

vector<int> frds[501];  // 친구 배열, 인덱스는 학번
int vis[501]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; 
    cin >> N >> M; // (2 ≤ N ≤ 500), (1 ≤ M ≤ 10000)

    for (int i = 0; i < M; i++) {
        int u, v; 
        cin >> u >> v; 
        frds[u].push_back(v);
        frds[v].push_back(u);
    }

    queue<int> Q; 
    int count = 0; 
    vis[1] = 1;
        
    /* 상근이의 친구 찾기 */
    for (int i = 0; i < frds[1].size(); i++) {
        count++; 
        vis[frds[1][i]] = 1; 
        Q.push(frds[1][i]);
    }

    /* 상근이의 친구의 친구 찾기 */
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop(); 
        for(int i = 0; i < frds[cur].size(); i++) {
            if (vis[frds[cur][i]]) continue; 
            vis[frds[cur][i]] = 1;
            count++; 
        }
    }    

    cout << count; 
    
    return 0;
}