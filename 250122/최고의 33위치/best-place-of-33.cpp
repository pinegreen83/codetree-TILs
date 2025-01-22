#include <iostream>

using namespace std;

int N;
int grid[20][20];

int check(int x, int y) {
    int ans = 0;

    for(int i=x; i<x+3; i++) {
        for(int j=y; j<y+3; j++) {
            if(grid[i][j] == 1) ans++;
        }
    }

    return ans;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    // Write your code here!
    for(int i=0; i<=N-3; i++) {
        for(int j=0; j<=N-3; j++) {
            ans = max(ans, check(i, j));
        }
    }
    cout << ans;

    return 0;
}
