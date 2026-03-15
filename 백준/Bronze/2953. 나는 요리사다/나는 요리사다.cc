#include <iostream>
#include <stack>

using namespace std; 

int score[5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int max = 0, max_index = 0; 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            int input; 
            cin >> input; 
            score[i] += input; 
        }
        if (score[i] > max) {
            max = score[i]; 
            max_index = i; 
        }
    }

    cout << max_index + 1 << ' ' << max;
    
    return 0;
}