#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort, binary_search

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<string> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<string> result; 
    string temp;
    
    for (int i = 0; i < M; i++) {
        cin >> temp; 

        if (binary_search(v.begin(), v.end(), temp)) {
            result.push_back(temp);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n'; 
    }

    return 0;
}