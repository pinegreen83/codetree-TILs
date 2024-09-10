#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, q;
    cin >> n >> q;

    int map[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> map[i][j];
    }

    int summap[n+1][n+1] = {};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            summap[i][j] = summap[i-1][j] + summap[i][j-1] + map[i-1][j-1] - summap[i-1][j-1];
        }
    }

    int x1, y1, x2, y2;
    for(int i=0; i<q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;

        cout << summap[x2][y2] - summap[x1][y2] - summap[x2][y1] + summap[x1][y1] << "\n";
    }

    return 0;
}