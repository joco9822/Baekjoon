// 입력: 노드의 개수 N, 간선의 개수 M, 시작 정점 V, 간선 x M
// 출력: V부터 방문한 점을 DFS/BFS 두 버전으로 출력 

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std; 

vector<int> graph[10001];
int vis[10001];  // bss 영역이므로 0으로 초기화 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, V;  // (1 ≤ N ≤ 1,000), (1 ≤ M ≤ 10,000)
    cin >> N >> M >> V;

    /* 간선 입력 받기 */
    for (int i = 0; i < M; i++) {
        int a, b; 
        cin >> a >> b; 
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    /* DFS */
    for (int i = 1; i <= N; i++) {
        // 스택은 LIFO 구조이므로, 작은 번호부터 방문하려면 내림차순 정렬 필요
        sort(graph[i].begin(), graph[i].end(), greater<>());
    }
    stack<int> S;
    S.push(V);
    while(!S.empty()) {
        int cur = S.top(); S.pop();

        if (vis[cur]) continue; 
        vis[cur] = 1;
        cout << cur << ' ';
        
        for (int i = 0; i < graph[cur].size(); i++) {
            if (!vis[graph[cur][i]]) {
                S.push(graph[cur][i]);
            } 
        }
    }
    cout << '\n';

    /* vis[] 배열 초기화 */
    for (int i = 1; i <= N; i++) {
        vis[i] = 0;
    }

    /* BFS */
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    queue<int> Q;
    Q.push(V);
    vis[V] = 1;
    cout << V << ' ';
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int i = 0; i < graph[cur].size(); i++) {
            if (!vis[graph[cur][i]]) {
                vis[graph[cur][i]] = 1; 
                cout << graph[cur][i] << ' ';
                Q.push(graph[cur][i]); 
            }
        }
    }
    
    return 0;
}