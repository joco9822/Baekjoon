#include <iostream>

using namespace std;

int paper[128][128];
int result[2];

bool check(int x, int y, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (paper[x + i][y + j] != paper[x][y]) 
                return false;
    return true;
}

void func(int x, int y, int n) {
    if (check(x, y, n)) {
        result[paper[x][y]]++;
        return;
    }

    int half = n / 2;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) 
            func(x + i * half, y + j * half, half);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> paper[i][j];
        
    func(0, 0, n);

    for (int i = 0; i < 2; i++) 
        cout << result[i] << '\n';
}
