#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int n, idx = 0;
    cin >> n;

    char map[n+1][n+1];
    for(int i=n; i>=1; i--) {
        for(int j=n; j>=1; j--) {
            map[j][i] = ('A' + idx++);
            idx %= 26;
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) cout << map[i][j] << " ";
        cout << "\n";
    }

    return 0;
}