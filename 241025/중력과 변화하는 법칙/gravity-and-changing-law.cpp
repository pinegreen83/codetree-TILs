#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

struct Next {
    int x, y, ch, dir;

    bool operator<(const Next& ne) const {
        return this->ch > ne.ch;
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

    bool isup = false;
    bool isdown = false;
    if(0 <= sx + dirs[0] && map[sx+dirs[0]][sy] == '#') {
        isup = true;
        q.push(Next{sx, sy, 0, 0});
        visited[sx][sy][0] = 0;
    }

    if(sx + dirs[1] < n && map[sx+dirs[1]][sy] == '#') {
        isdown = true;
        q.push(Next{sx, sy, 1, 0});
        visited[sx][sy][1] = 0;
    }

    if(!isup && !isdown) {
        cout << -1;
        return 0;
    }

    while(!q.empty()) {
        Next now = q.top();
        q.pop();

        int x = now.x;
        int y = now.y;
        int grav = now.dir;
        int chan = now.ch;

        if(visited[x][y][grav] < chan) continue;

        int nextX = x;
        while(true) {
            int newX = nextX + dirs[grav];
            if(newX < 0 || newX >= n || map[newX][y] == '#') {
                break;
            }
            nextX = newX;
        }

        if(map[nextX][y] == 'D') {
            cout << chan;
            return 0;
        }

        for(int i=-1; i<=1; i+=2) {
            int ny = y + i;
            if(ny < 0 || ny >= m || map[nextX][ny] == '#') continue;

            if(visited[nextX][ny][grav] > chan) {
                visited[nextX][ny][grav] = chan;
                q.push(Next{nextX, ny, chan, grav});
            }

            int nextDir = 1 - grav;
            if(visited[nextX][ny][nextDir] > chan + 1) {
                visited[nextX][ny][nextDir] = chan + 1;
                q.push(Next{nextX, ny, chan+1, nextDir});
            }
        }
    }
    cout << -1;

    return 0;
}