#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 0;
vector<vector<char>> map;
vector<string> direc = {"하", "좌", "상", "우"};
vector<vector<int>> dirs = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // 하, 좌, 상, 우

void light(int x, int y, int dir)
{
    int cnt = 0;
    x += dirs[dir][0];
    y += dirs[dir][1];
    while(1 <= x && x <= n && 1 <= y && y <= m)
    {
        if(map[x][y] == '/')
        {
            switch (dir)
            {
                case 0: dir = 1; break;
                case 1: dir = 0; break;
                case 2: dir = 3; break;
                case 3: dir = 2; break;
            }
        }
        else
        {
            switch (dir)
            {
                case 0: dir = 3; break;
                case 1: dir = 2; break;
                case 2: dir = 1; break;
                case 3: dir = 0; break;
            }
        }
        cnt++;
        x += dirs[dir][0];
        y += dirs[dir][1];
    }
    ans = max(ans, cnt);
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    map = vector<vector<char>>(n+2, vector<char>(m+2));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cin >> map[i][j];
    }

    vector<vector<int>> move = {{m, 0, 1}, {n, 1, 0}, {m, 0, -1}, {n, -1, 0}};
    int startx = 0, starty = 0;
    for(int t=0; t<4; t++)
    {
        for(int i=0; i<move[t][0]; i++)
        {
            startx += move[t][1];
            starty += move[t][2];
            light(startx, starty, t);
        }
        startx += move[t][1];
        starty += move[t][2];
    }
    cout << ans;

    return 0;
}