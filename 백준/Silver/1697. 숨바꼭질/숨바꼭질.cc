#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dist[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    fill(dist, dist + 100005, -1);

    queue<int> Q;
    Q.push(n);
    dist[n] = 0;

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();

        if(cur == k) {
            cout << dist[cur];
            return 0;
        }

        int next_pos[3] = {cur - 1, cur + 1, cur * 2};

        for(int nxt : next_pos) {
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[nxt] != -1) continue;

            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }

    return 0;
}