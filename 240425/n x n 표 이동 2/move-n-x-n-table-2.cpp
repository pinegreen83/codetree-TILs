#include <iostream>
#include <vector>

using namespace std;

int n, cnt = 0;
vector<vector<int>> map, dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isin(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < n;
}

void DFS(int x, int y, int now)
{
    cnt = max(now, cnt);
    for(int i=0; i<4; i++)
    {
        int dirx = x + dirs[i][0];
        int diry = y + dirs[i][1];
        if(isin(dirx, diry))
        {
            if(map[x][y] < map[dirx][diry])
            {
                DFS(dirx, diry, now+1);
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    map = vector<vector<int>>(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }

    int maxlen = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cnt = 0;
            DFS(i, j, 1);
            maxlen = max(maxlen, cnt);
        }
    }
    cout << maxlen;

    return 0;
}