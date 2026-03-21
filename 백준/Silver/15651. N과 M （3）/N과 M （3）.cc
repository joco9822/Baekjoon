#include <iostream>

using namespace std; 

int arr[8]; 
int n, m; 

void func(int k) {
    if (k == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        arr[k] = i+1; 
        func(k+1);
    }
    
    return; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m; 
    func(0);
    
    return 0;
}