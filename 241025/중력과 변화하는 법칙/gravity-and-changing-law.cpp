#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

struct Next {
    int x, y, ch, dir;

    bool operator<(const Next& ne) const {
        return this->ch < ne.dir;
    }
};

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;

    int sx, sy;
    vector<vector<char>> map(n, vector<char>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'C') {
                sx = i;
                sy = j;
            }
        }
    }

    int dirs[2] = {-1, 1};
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2, INF)));
    priority_queue<Next> q;
    q.push(Next{sx, sy, 0, 0});
    q.push(Next{sx, sy, 0, 1});

    visited[sx][sy][0] = 0;
    visited[sx][sy][1] = 0;

    while(!q.empty()) {
        Next now = q.top();
        q.pop();

        bool check = false;
        int nextX = now.x + dirs[now.dir];
        while(0 <= nextX && nextX < n) {
            if(map[nextX][now.y] == '#') {
                nextX -= dirs[now.dir];
                check = true;
                break;
            }
            nextX += dirs[now.dir];
        }

        if(!check) continue;

        if(map[nextX][now.y] == 'D') {
            cout << now.ch;
            return 0;
        }

        for(int i=-1; i<=1; i+=2) {
            int ny = now.y + i;
            if(0 > ny || ny >= m) continue; 

            if(visited[nextX][ny][now.dir] > now.ch) {
                visited[nextX][ny][now.dir] = now.ch;
                q.push(Next{nextX, ny, now.ch, now.dir});
            }

            int nextDir = 1 - now.dir;
            if(visited[nextX][ny][nextDir] > now.ch+1) {
                visited[nextX][ny][nextDir] = now.ch+1;
                q.push(Next{nextX, ny, now.ch+1, nextDir});
            }
        }
    }
    cout << -1;

    return 0;
}