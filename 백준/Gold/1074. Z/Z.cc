#include <iostream>

using namespace std;

int arr[502][502]; 
int count=0; 

int func(int n, int r, int c) {
    if (n==0) return 0; 

    // half = 2^(n-1) : half는 현재 바둑판 크기의 중앙점임 
    int half = 1<<(n-1); 

    // 2 사분면 
    if (r<half && c<half) return func(n-1, r, c); 
    // 1 사분면 
    if (r<half && c>=half) return half*half + func(n-1, r, c-half);
    // 3 사분면 
    if (r>=half && c<half) return 2*half*half + func(n-1, r-half, c);
    // 4 사분면 
    if (r>=half && c>=half) return 3*half*half + func(n-1, r-half, c-half); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, c; 
    cin >> n >> r >> c;  

    cout << func(n, r, c);

    return 0; 
}