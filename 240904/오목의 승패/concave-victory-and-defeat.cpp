#include <iostream>
using namespace std;

int ans = 0, ansx, ansy;
int map[20][20], dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
bool visited[20][20] = {};

bool isin(int x, int y) {
    return 1 <= x && x <= 19 && 1 <= y && y <= 19;
}

void dfs(int dir, int cnt, int x, int y, int type) {
    int dirx = x + dirs[dir][0];
    int diry = y + dirs[dir][1];

    if(isin(dirx, diry) && !visited[dirx][diry] && map[dirx][diry] == type) {
        visited[dirx][diry] = true;
        dfs(dir, cnt+1, dirx, diry, type);
    }
    else {
        if(cnt == 5) {
            ans = type;
            ansx = dirx - dirs[dir][0] * 5;
            ansy = diry - dirs[dir][1] * 5;
        }
        return;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    
    for(int i=1; i<=19; i++) {
        for(int j=1; j<=19; j++) cin >> map[i][j];
    }

    for(int i=1; i<=19; i++) {
        for(int j=1; j<=19; j++) {
            if(map[i][j] != 0 && !visited[i][j]) {
                visited[i][j] = true;
                for(int d=0; d<8; d++) {
                    dfs(d, 1, i, j, map[i][j]);
                }
            }
        }
    }
    if(ans != 0) cout << ans << "\n" << ansx << " " << ansy;
    else cout << ans;

    return 0;
}