#include <iostream>
using namespace std;

int map[20][20], dirs[3][2] = {{-1, 1}, {0, 1}, {1, 1}};

bool isin(int x, int y) {
    return 1 <= x && x <= 19 && 1 <= y && y <= 19;
}

int main() {
    // 여기에 코드를 작성해주세요.
    
    for(int i=1; i<=19; i++) {
        for(int j=1; j<=19; j++) cin >> map[i][j];
    }

    int dirx, diry, cnt, ans = 0, ansx, ansy;
    bool find = false;
    for(int i=1; i<=19; i++) {
        if(find) break;
        for(int j=1; j<=19; j++) {
            if(find) break;
            if(map[i][j] != 0) {
                for(int d=0; d<3; d++) {
                    dirx = i + dirs[d][0];
                    diry = j + dirs[d][1];
                    cnt = 1;

                    while(isin(dirx, diry) && map[i][j] == map[dirx][diry]) {
                        cnt++;
                        dirx += dirs[d][0];
                        diry += dirs[d][1];
                    }
                    if(cnt == 5) {
                        find = true;
                        ans = map[i][j];
                        ansx = i;
                        ansy = j;
                    }
                }
            }
        }
    }
    if(ans != 0) cout << ans << "\n" << ansx << " " << ansy;
    else cout << ans;

    return 0;
}