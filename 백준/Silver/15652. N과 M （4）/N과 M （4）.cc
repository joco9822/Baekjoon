#include <iostream>

using namespace std; 

int arr[9];
int n, m; 

void func(int k, int start) {
    if (k == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return; 
    }

    for (int i = start; i < n; i++) {
        arr[k] = i+1; 
        func(k+1, i);
    }
    return; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m; 
    func(0, 0);
    
    return 0;
}