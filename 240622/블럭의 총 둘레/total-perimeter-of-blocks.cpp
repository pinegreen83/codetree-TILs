#include <iostream>
#include <queue>

using namespace std;

int n, ans = 0;
int map[102][102], dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool visited[102][102];
bool external[102][102];

bool isin(int x, int y)
{
    return 0 <= x && x <= 101 && 0 <= y && y <= 101;
}

void findOutside(int x, int y)
{
    external[x][y] = true;

    for(int d=0; d<4; d++)
    {
        int dirx = x + dirs[d][0];
        int diry = y + dirs[d][1];

        if(isin(dirx, diry) && !external[dirx][diry] && map[dirx][diry] == 0)
        {
            findOutside(dirx, diry);
        }
    }
}

void DFS(int x, int y)
{
    for(int d=0; d<4; d++)
    {
        int dirx = x + dirs[d][0];
        int diry = y + dirs[d][1];
        
        // 인접한 방향에 외부 빈 공간이 있는 경우, 둘레에 해당
        if(!isin(dirx, diry) || (map[dirx][diry] == 0 && external[dirx][diry]))
        {
            ans++;
        }
        
        // 인접한 방향으로 이동할 수 있는 경우 DFS 호출
        if(isin(dirx, diry) && !visited[dirx][diry] && map[dirx][diry] == 1)
        {
            visited[dirx][diry] = true;
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

    findOutside(0, 0);

    for(int i=1; i<=100; i++)
    {
        for(int j=1; j<=100; j++)
        {
            if(!visited[i][j] && map[i][j] == 1)
            {
                visited[i][j] = true;
                DFS(i, j);
            }
        }
    }
    cout << ans;

    return 0;
}