#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Stick {
    int x, y, dir;
};

int n;

bool isin(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> map[i][j];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<bool>> dirs = {{1, 0, 1}, {0, 1, 1}, {1, 1, 1}};
    vector<vector<int>> move = {{0, 1}, {1, 0}, {1, 1}};
    dp[0][0] = 1;
    dp[0][1] = 1;
    queue<Stick> q;
    q.push(Stick{0, 1, 0});

    while(!q.empty()) {
        Stick now = q.front();
        q.pop();

        for(int i=0; i<3; i++) {
            int dir = dirs[now.dir][i];
            if(dir == 1) {
                int dirx = now.x + move[i][0];
                int diry = now.y + move[i][1];
                if(isin(dirx, diry) && map[dirx][diry] != 1) {
                    if(i == 2) {
                        if(map[dirx-1][diry] == 0 && map[dirx][diry-1] == 0) {
                            dp[dirx][diry]++;
                            q.push(Stick{dirx, diry, i});
                        }
                    }
                    else {
                        dp[dirx][diry]++;
                        q.push(Stick{dirx, diry, i});
                    }
                }
            }
        }
    }
    cout << dp[n-1][n-1];

    return 0;
}