#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 0;
vector<vector<int>> map, dirs = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // 아래, 왼, 위, 오른

void light(int x, int y, int dir)
{
    int cnt = 0;
    x += dirs[dir][0];
    y += dirs[dir][1];
    while(1 <= x && x <= n && 1 <= y && y <= n)
    {
        switch (dir)
        {
            case 0:
                if(map[x][y]) dir = 1;
                else dir = 3;
                break;
            case 1:
                if(map[x][y]) dir = 0;
                else dir = 2;
                break;
            case 2:
                if(map[x][y]) dir = 3;
                else dir = 1;
                break;
            case 3:
                if(map[x][y]) dir = 2;
                else dir = 0;
                break;
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
    map = vector<vector<int>>(n+2, vector<int>(m+2));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) 
        {
            char now;
            cin >> now;
            if(now == '/') map[i][j] = 1;

        }
    }

    vector<vector<int>> move = {{n, 0, 1}, {m, 1, 0}, {n, 0, -1}, {m, -1, 0}};
    int startx = 0, starty = 0;
    for(int t=0; t<4; t++)
    {
        for(int i=0; i<move[t][0]; i++)
        {
            startx += move[t][1];
            starty += move[t][2];
            light(startx, starty, 0);
        }
        startx += move[t][1];
        starty += move[t][2];
    }
    cout << ans;

    return 0;
}