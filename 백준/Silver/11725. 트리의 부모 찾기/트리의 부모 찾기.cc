#include <iostream>
#include <queue> 
#include <vector> 

using namespace std; 

vector<int> tree[100001]; 
int parent[100001]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;  // (2 ≤ N ≤ 100,000)

    for(int i = 0; i < N-1; i++) {
        int u, v; 
        cin >> u >> v; 
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    queue<int> Q; 
    Q.push(1); 
    parent[1] = -1; 

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop(); 

        for (int i = 0; i < tree[cur].size(); i++) {
            if (parent[tree[cur][i]] != 0) continue;
            Q.push(tree[cur][i]); 
            parent[tree[cur][i]] = cur; 
        }
    }

    for(int i = 0; i < N-1; i++) {
        cout << parent[i+2] << '\n'; 
    }
    
    return 0;
}