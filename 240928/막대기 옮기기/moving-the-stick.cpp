#include <iostream>
#include <vector>

#define Right 1
#define Down 2
#define RightDown 3

using namespace std;

int n, ans = 0;
vector<vector<int>> map;

bool isin(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Backtrack(int x, int y) {
    if(x == n-1 && y == n-1) {
        ans++;
        return;
    }

    switch(map[x][y]) {
        case Right:
            if(isin(x, y+1) && map[x][y+1] == 0) {
                map[x][y+1] = Right;
                Backtrack(x, y+1);
                map[x][y+1] = 0;
            }
            if(isin(x+1, y) && isin(x+1, y+1) && isin(x, y+1)) {
                if(map[x+1][y] == 0 && map[x+1][y+1] == 0 && map[x][y+1] == 0) {
                    map[x+1][y+1] = RightDown;
                    Backtrack(x+1, y+1);
                    map[x+1][y+1] = 0;
                }
            }
            break;
        case Down:
            if(isin(x+1, y) && map[x+1][y] == 0) {
                map[x+1][y] = Down;
                Backtrack(x+1, y);
                map[x+1][y] = 0;
            }
            if(isin(x+1, y) && isin(x+1, y+1) && isin(x, y+1)) {
                if(map[x+1][y] == 0 && map[x+1][y+1] == 0 && map[x][y+1] == 0) {
                    map[x+1][y+1] = RightDown;
                    Backtrack(x+1, y+1);
                    map[x+1][y+1] = 0;
                }
            }
            break;
        case RightDown:
            if(isin(x, y+1) && map[x][y+1] == 0) {
                map[x][y+1] = Right;
                Backtrack(x, y+1);
                map[x][y+1] = 0;
            }
            if(isin(x+1, y) && map[x+1][y] == 0) {
                map[x+1][y] = Down;
                Backtrack(x+1, y);
                map[x+1][y] = 0;
            }
            if(isin(x+1, y) && isin(x+1, y+1) && isin(x, y+1)) {
                if(map[x+1][y] == 0 && map[x+1][y+1] == 0 && map[x][y+1] == 0) {
                    map[x+1][y+1] = RightDown;
                    Backtrack(x+1, y+1);
                    map[x+1][y+1] = 0;
                }
            }
            break;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    map = vector<vector<int>>(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) map[i][j] = -1;
        }
    }

    map[0][1] = 1;
    Backtrack(0, 1);
    cout << ans;

    return 0;
}