#include <iostream>

using namespace std;

int ans = 0;
int map[1001][1001] = {0};
int pinmap[1001][1001] = {0};
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isin(int x, int y) {
    return 0 <= x && x <= 1000 && 0 <= y && y <= 1000;
}

void isComfort(int x, int y) {
    for(int i=0; i<4; i++) {
        int dirx = x + dirs[i][0];
        int diry = y + dirs[i][1];

        if(isin(dirx, diry) && map[dirx][diry] != 0) {
            pinmap[x][y]++;
            pinmap[dirx][diry]++;
            if(pinmap[dirx][diry] == 3) ans++;
            else if(pinmap[dirx][diry] == 4) ans--;
        }
    }
    if(pinmap[x][y] == 3) ans++;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n, x, y, pinx, piny;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> x >> y;
        map[x][y] = 1;

        isComfort(x, y);

        cout << ans << "\n";
    }

    return 0;
}