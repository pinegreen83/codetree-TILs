#include <iostream>

using namespace std;

int n, maxx = 0, maxy = 0, ans = 0;
int map[101][101], dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool visited[101][101];

void DFS(int x, int y)
{
    for(int d=0; d<4; d++)
    {
        int dirx = x + dirs[d][0];
        int diry = y + dirs[d][1];
        if(!visited[dirx][diry] && map[dirx][diry] == 1)
        {
            visited[dirx][diry] = true;
            maxx = max(maxx, dirx);
            maxy = max(maxy, diry);
            DFS(dirx, diry);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int r, c;
        cin >> r >> c;
        map[r][c] = 1;
    }

    for(int i=1; i<=100; i++)
    {
        for(int j=1; j<=100; j++)
        {
            if(!visited[i][j] && map[i][j] == 1)
            {
                visited[i][j] = true;
                maxx = 0;
                maxy = 0;
                DFS(i, j);
                ans += (maxx - i + 1) * 2 + (maxy - j + 1) * 2;
            }
        }
    }
    cout << ans;

    return 0;
}