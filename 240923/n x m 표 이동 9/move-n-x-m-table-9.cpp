#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

struct Node {
    int x;
    int y;
    bool check;
    int cnt;
};

bool isin(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> map(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> map[i][j];
    }

    queue<Node> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    if(map[0][0]) q.push(Node{0, 0, true, 1});
    else q.push(Node{0, 0, false, 1});
    visited[0][0] = true;

    int ans = -1;
    while(!q.empty()) {
        Node now = q.front();
        q.pop();

        if(now.x == n-1 && now.y == m-1) {
            ans = now.cnt;
            break;
        }

        for(int d=0; d<4; d++) {
            int dirx = now.x + dirs[d][0];
            int diry = now.y + dirs[d][1];

            if(isin(dirx, diry) && !visited[dirx][diry]) {
                if(now.check) {
                    if(map[dirx][diry] == 0) {
                        visited[dirx][diry] = true;
                        q.push(Node{dirx, diry, true, now.cnt+1});
                    }
                }
                else {
                    if(map[dirx][diry] == 1) {
                        visited[dirx][diry] = true;
                        q.push(Node{dirx, diry, true, now.cnt+1});
                    }
                    else {
                        visited[dirx][diry] = true;
                        q.push(Node{dirx, diry, false, now.cnt+1});
                    }
                }
            }
        }
    }
    cout << ans;

    return 0;
}