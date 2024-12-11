#include <iostream>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    int cnt = 1;
    int map[n][n];

    for(int j=0; j<n; j++) {
        for(int i=0; i<n; i++) {
            map[i][j] = cnt++;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cout << map[i][j] << " ";
        cout << "\n";
    }

    return 0;
}