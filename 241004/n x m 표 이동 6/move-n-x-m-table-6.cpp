#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int x, y, move;
    bool check;
};

int n, m, t;

bool isin(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    // 여기에 코드를 작성해주세요.

    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    cin >> n >> m >> t;

    vector<vector<int>> map(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> map[i][j];
    }

    vector<vector<vector<bool>>> visited(2, vector<vector<bool>>(n, vector<bool>(m, false)));
    queue<Node> q;
    q.push(Node{0, 0, 0, false});
    visited[0][0][0] = true;

    int end = -1;
    while(!q.empty()) {
        Node now = q.front();
        q.pop();

        if(now.x == n-1 && now.y == m-1) {
            if(now.move <= t) {
                cout << now.move;
            } else {
                cout << "Fail";
            }
            return 0;
        }

        for(int d=0; d<4; d++) {
            int dirx = now.x + dirs[d][0];
            int diry = now.y + dirs[d][1];

            if(isin(dirx, diry)) {
                if(!now.check && !visited[0][dirx][diry]) {
                    if(map[dirx][diry] == 0 || map[dirx][diry] == 2) {
                        visited[0][dirx][diry] = true;
                        q.push(Node{dirx, diry, now.move+1, map[dirx][diry] == 2 ? true : now.check});
                    }
                }
                if(now.check && !visited[1][dirx][diry]) {
                    visited[1][dirx][diry] = true;
                    q.push(Node{dirx, diry, now.move+1, true});
                }
            }
        }
    }
    cout << "Fail";

    return 0;
}