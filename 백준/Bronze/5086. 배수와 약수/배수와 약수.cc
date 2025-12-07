#include <iostream>
using namespace std;

int main() {
    int a, b;

    while (true) {
        cin >> a >> b;

        // 종료 조건: 두 수가 모두 0일 때
        if (a == 0 && b == 0) {
            break;
        }

        if (b % a == 0) {
            // b를 a로 나누었을 때 나머지가 0이면 a는 b의 약수
            cout << "factor" << endl;
        } 
        else if (a % b == 0) {
            // a를 b로 나누었을 때 나머지가 0이면 a는 b의 배수
            cout << "multiple" << endl;
        } 
        else {
            // 둘 다 아닌 경우
            cout << "neither" << endl;
        }
    }

    return 0;
}