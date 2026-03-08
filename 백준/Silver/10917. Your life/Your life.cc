/* 입력
    - N: 상황의 번호 (1번 부터 시작)
    - M: 선택할 수 있는 변화, (x, y), (x < y) **순서 있음** */
#include <iostream>
#include <queue>

using namespace std; 

vector<int> graph[100001];
int dis[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    /* 입력: 상황, 변화 */
    int N, M; 
    cin >> N >> M; 
    for(int i = 0; i < M; i++) {
        int u, v; 
        cin >> u >> v; 
        graph[u].push_back(v);   // 순서 있음 = 단방향 
    }

    /* dis 배열 초기화 */
    for(int i = 0; i <= N; i++) {
        dis[i] = -1;
    }

    queue<int> Q; 
    Q.push(1); 
    dis[1] = 0; 
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop(); 
        if (cur == N) {
            cout << dis[N];
            return 0; 
        }
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (dis[next] != -1) continue; 
            dis[next] = dis[cur] + 1; 
            Q.push(next); 
        }
    }

    cout << -1; 
        
    return 0;
}