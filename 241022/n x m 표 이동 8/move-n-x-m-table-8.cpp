#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

struct Block{
    int x, y, cnt, ks;
};

int k, n, m;

bool isin(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> k >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> map[i][j];
    }

    int move[12][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(n, vector<int>(m, 1e9)));
    dp[0][0][0] = 0;

    queue<Block> q;
    q.push({0, 0, 0, 0});

    while(!q.empty()) {
        Block now = q.front();
        q.pop();

        int start = 8;
        if(now.ks < k) start = 0;
        for(int d=start; d<12; d++) {
            int dirx = now.x + move[d][0];
            int diry = now.y + move[d][1];

            if(isin(dirx, diry)) {
                if(map[dirx][diry] == 1) continue;

                if(d < 8 && now.ks < k) {
                    if(dp[now.ks+1][dirx][diry] > now.cnt + 1) {
                        dp[now.ks+1][dirx][diry] = now.cnt + 1;
                        q.push({dirx, diry, now.cnt+1, now.ks+1});
                    }
                }
                else {
                    if(dp[now.ks][dirx][diry] > now.cnt + 1) {
                        dp[now.ks][dirx][diry] = now.cnt + 1;
                        q.push({dirx, diry, now.cnt+1, now.ks});
                    }
                }
            }
        }
    }

    int ans = INF;
    for(int i=0; i<=k; i++) {
        ans = min(ans, dp[i][n-1][m-1]);
    }
    cout << (ans == INF ? -1 : ans);

    return 0;
}