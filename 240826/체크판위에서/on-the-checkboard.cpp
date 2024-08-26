#include <iostream>

#define MAX_N 15

using namespace std;

int r, c, ans = 0;
char str[MAX_N][MAX_N];

bool isin(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
}

void backtrack(int x, int y, char now) {
    if(x == r-1 && y == c - 1) {
        ans++;
        return;
    }
    for(int i=x+1; i<r; i++) {
        for(int j=y+1; j<c; j++) {
            if(now != str[i][j]) backtrack(i, j, str[i][j]);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> r >> c;

    for(int i=0; i<r; i++) cin >> str[i];

    backtrack(0, 0, str[0][0]);
    cout << ans;

    return 0;
}