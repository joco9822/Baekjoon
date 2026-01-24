#include <iostream>
#include <string>

using namespace std; 

int image[2000][2000];

void func(int x, int y, int n) {
    if (n == 1) {
        cout << image[x][y];
        return;
    }

    bool zero = true, one = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (image[x + i][y +j] == 0) {
                one = false;
            } else {
                zero = false;
            }
        }
    }

    if (zero) {
        cout << 0;
        return;
    }
    else if (one) {
        cout << 1;
        return;
    }
    else {
        cout << '(';
        int half = n / 2;
        func(x, y, half);
        func(x, y + half, half);
        func(x + half, y, half);
        func(x + half, y + half, half);
        cout << ')';
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string str; 
        cin >> str;

        for (int j = 0; j < N; ++j) {
            image[i][j] = str[j] - '0';
        }
    }

    func(0, 0, N);

    return 0; 
}