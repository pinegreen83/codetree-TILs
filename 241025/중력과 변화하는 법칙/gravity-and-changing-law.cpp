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

int n, m, dirs[2] = {-1, 1};

int applyGravity(int x, int y, int d, vector<vector<char>>& map) {
    while(true) {
        int newX = x + dirs[d];
        if(newX < 0 || newX >= n) return -1;
        if(map[newX][y] == '#') {
            return x;
        }
        if(map[newX][y] == 'D') {
            return newX;
        }
        x = newX;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
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

    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2, INF)));
    priority_queue<Next> q;

    for(int i=0; i<=1; i++) {
        int change = (i == 1 ? 0 : 1);
        int newX = applyGravity(sx, sy, i, map);
        
        if(newX != -1) {
            if(visited[newX][sy][i] > change) {
                q.push(Next{newX, sy, change, i});
                visited[newX][sy][i] = change;
            }
        }
    }

    while(!q.empty()) {
        Next now = q.top();
        q.pop();

        int x = now.x;
        int y = now.y;
        int grav = now.dir;
        int chan = now.ch;

        if(visited[x][y][grav] < chan) continue;

        if(map[x][y] == 'D') {
            cout << chan;
            return 0;
        }
    
        for(int i=-1; i<=1; i+=2) {
            int ny = y + i;

            if(ny < 0 || ny >= m || map[x][ny] == '#') continue;

            int nextX = applyGravity(x, ny, grav, map);

            if(nextX != -1 && visited[nextX][ny][grav] > chan) {
                visited[nextX][ny][grav] = chan;
                q.push(Next{nextX, ny, chan, grav});
            }

            int nextDir = 1 - grav;
            nextX = applyGravity(x, ny, nextDir, map);

            if(nextX != -1 && visited[nextX][ny][nextDir] > chan + 1) {
                visited[nextX][ny][nextDir] = chan + 1;
                q.push(Next{nextX, ny, chan+1, nextDir});
            }
        }
    }
    cout << -1;

    return 0;
}