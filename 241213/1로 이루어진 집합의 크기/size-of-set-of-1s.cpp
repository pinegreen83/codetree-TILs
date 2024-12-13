#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

bool isin(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> map[i][j];
    }

    int cnt, idx = 0;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<int> blocks;
    vector<vector<int>> visited(n, vector<int>(m, -1));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 1) {
                if(visited[i][j] != -1) continue;
                queue<pair<int, int>> q;
                visited[i][j] = idx;
                q.push({i, j});
                cnt = 0;
                while(!q.empty()) {
                    pair<int, int> now = q.front();
                    q.pop();
                    cnt++;

                    for(int d=0; d<4; d++) {
                        int dirx = now.first + dirs[d][0];
                        int diry = now.second + dirs[d][1];

                        if(isin(dirx, diry) && visited[dirx][diry] == -1 && map[dirx][diry] == 1) {
                            q.push({dirx, diry});
                            visited[dirx][diry] = idx;
                        }
                    }
                }
                idx++;
                blocks.emplace_back(cnt);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 0) {
                int now = 1;
                vector<bool> check(blocks.size(), false);
                for(int d=0; d<4; d++) {
                    int dirx = dirs[d][0] + i;
                    int diry = dirs[d][1] + j;

                    if(isin(dirx, diry) && map[dirx][diry] == 1) {
                        if(!check[visited[dirx][diry]]) {
                            now += blocks[visited[dirx][diry]];
                            check[visited[dirx][diry]] = true;
                        }
                    }
                }
                ans = max(ans, now);
            }
            else ans = max(ans, blocks[map[i][j]]);
        }
    }
    cout << ans;

    return 0;
}