#include <iostream>
#include <queue> 
#define X first
#define Y second 

using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B; 
    cin >> A >> B; 

    queue<pair<long long, int>> Q; 
    Q.push({A, 1});
    while(!Q.empty()) {
        pair<long long, int> cur = Q.front(); Q.pop();
        if (cur.X == B) {
            cout << cur.Y; 
            return 0;
        }

        cur.Y++; 

        if (cur.X * 2 < B || cur.X * 2 == B) Q.push({cur.X * 2, cur.Y}); 
        if (((cur.X * 10) + 1) < B || ((cur.X * 10) + 1) == B) Q.push({(cur.X * 10) + 1, cur.Y});
        
    }
    
    cout << -1;
    return 0;
}