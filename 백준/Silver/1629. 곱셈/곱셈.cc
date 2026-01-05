#include <iostream>

using namespace std;
using ll = long long;

ll POW(ll a, ll b, ll m) {
    if (b == 0) return 1 % m;
    
    ll val = POW(a, b / 2, m);
    val = (val * val) % m;
    
    if (b % 2 == 0) return val;
    return (val * (a % m)) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll a, b, c;
    if (!(cin >> a >> b >> c)) return 0;
    
    ll val = POW(a, b, c);
    
    cout << val << "\n";

    return 0;
}
