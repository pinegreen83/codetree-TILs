#include <iostream>
using namespace std;

int map[20][20], dirs[4][2] = {{-1, 1}, {0, 1}, {1, 0}, {1, 1}};

bool isin(int x, int y) {
    return 1 <= x && x <= 19 && 1 <= y && y <= 19;
}

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=1; i<=19; i++) {
        for(int j=1; j<=19; j++) cin >> map[i][j];
    }

    int dirx, diry, cnt, ansx, ansy;
    for(int i=1; i<=19; i++) {
        for(int j=1; j<=19; j++) {
            if(map[i][j] != 0) {
                for(int d=0; d<4; d++) {
                    ansx = i;
                    ansy = j;
                    dirx = i + dirs[d][0];
                    diry = j + dirs[d][1];
                    cnt = 1;

                    while(isin(dirx, diry) && map[i][j] == map[dirx][diry]) {
                        cnt++;
                        dirx += dirs[d][0];
                        diry += dirs[d][1];
                    }
                    ansx = i;
                    ansy = j;

                    int difcnt = 0;
                    dirx = i - dirs[d][0];
                    diry = j - dirs[d][1];
                    while(isin(dirx, diry) && map[i][j] == map[dirx][diry]) {
                        cnt++;
                        difcnt++;
                        dirx -= dirs[d][0];
                        diry -= dirs[d][1];
                    }

                    if(cnt == 5) {
                        if(difcnt) cout << map[i][j] << "\n" << dirx+dirs[d][0] << " " << diry+dirs[d][1];
                        else cout << map[i][j] << "\n" << i << " " << j;
                        return 0;
                    }
                }
            }
        }
    }
    cout << 0;

    return 0;
}