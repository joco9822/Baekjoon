// 간선이 없는 노드도 하나의 연결 요소로 침 

#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

vector<int> graph[1001];  // 노드(인덱스) 1~1000까지
int vis[1001]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; 
    cin >> N >> M;  // (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 

    for (int i = 0; i < M; i++) {
        int u, v;  // (1 ≤ u, v ≤ N, u ≠ v) 
        cin >> u >> v; 
        graph[u].push_back(v); 
        graph[v].push_back(u); 
    }

    /* BFS */
    int count = 0; 
    queue<int> Q; 
    for (int n = 1; n <= N; n++) {
        if (vis[n] == 1) continue; 

        Q.push(n);
        vis[n] = 1; 
        count++; 
        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for (int i = 0; i < graph[cur].size(); i++) {
                if (vis[graph[cur][i]] == 1) continue; 
                Q.push(graph[cur][i]); 
                vis[graph[cur][i]] = 1; 
            }
        }
    }

    cout << count; 
    
    return 0;
}