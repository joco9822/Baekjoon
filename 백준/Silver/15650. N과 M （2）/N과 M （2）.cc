#include <iostream>

using namespace std; 

int n, m;       // n은 원소의 개수, m은 수열의 크기 
int arr[9];     // 수열을 담을 배열
bool isused[9];  // 원소(index) 사용 여부 

void func(int k) {
    /* 수열의 마지막 자리까지 모두 찾으면 => 출력 */
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';  // 참고로 arr[] 배열 초기화는 안해도 됨
        }
        cout << '\n';
        return;
    }

    /* 수열의 다음 자리 찾기 */
    for (int i = 0; i < n; i++) {
        if (k != 0) {
                if (arr[k-1] > i) continue;
        }
        if (!isused[i]) {
            arr[k] = i+1; 
            isused[i] = true;
            func(k+1);
            isused[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m; 

    func(0);  // k번째 자리를 찾기 위해 호출 
    
    return 0;
}