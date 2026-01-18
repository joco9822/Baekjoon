#include <iostream>

using namespace std; 

int paper[2200][2200];
int N; 
int count[3] = {0}; 

bool check(int x, int y, int n) {
    int start = paper[x][y];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(start != paper[x + i][y + j])
                return false; 
        }
    }
    return true; 
}

void func(int x, int y, int n) {
    if (check(x, y, n)) {
        count[paper[x][y] + 1] += 1; 
        return; 
    }

    int m = n / 3; 
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            func(x + i * m, y + j * m, m);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;  
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    func(0, 0, N);

    cout << count[0] << '\n';
    cout << count[1] << '\n';
    cout << count[2] << '\n';
    
    return 0;
}