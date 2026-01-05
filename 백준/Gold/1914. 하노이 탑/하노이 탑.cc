#include <bits/stdc++.h>
using namespace std;

// 하노이 재귀 함수
void func(int a, int b, int n){
    if(n == 1){
        cout << a << ' ' << b << '\n';
        return;
    }
    func(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n';
    func(6-a-b, b, n-1);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    string res = "1";
    for(int i = 0; i < k; i++) {
        int carry = 0;
        for(int j = res.size() - 1; j >= 0; j--) {
            int num = (res[j] - '0') * 2 + carry;
            res[j] = (num % 10) + '0';
            carry = num / 10;
        }
        if(carry) res = to_string(carry) + res;
    }

    res[res.size() - 1]--; 
    
    cout << res << '\n';

    if(k <= 20) {
        func(1, 3, k);
    }

    return 0;
}
