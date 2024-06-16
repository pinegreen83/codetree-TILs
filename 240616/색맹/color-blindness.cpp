#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> map, dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<bool>> visited;

void DFS(bool diff, int x, int y, int color)
{
    for(int i=0; i<4; i++)
    {
        int dirx = x + dirs[i][0];
        int diry = y + dirs[i][1];
        if(0 <= dirx && dirx < n && 0 <= diry && diry < n)
        {
            if(!visited[dirx][diry])
            {
                if(!diff && map[dirx][diry] == color)
                {
                    visited[dirx][diry] = true;
                    DFS(diff, dirx, diry, color);
                }
                if(diff)
                {
                    if(color != 2)
                    {
                        if(map[dirx][diry] != 2)
                        {
                            visited[dirx][diry] = true;
                            DFS(diff, dirx, diry, color);
                        }
                    }
                    else
                    {
                        if(map[dirx][diry] == 2)
                        {
                            visited[dirx][diry] = true;
                            DFS(diff, dirx, diry, color);
                        }
                    }
                }
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
            char now;
            cin >> now;
            switch(now)
            {
                case 'G':
                    map[i][j] = 1;
                    break;
                case 'B':
                    map[i][j] = 2;
                    break;
            }
        }
    }

    vector<int> ans(2, 0);
    bool check = false;
    for(int t=0; t<2; t++)
    {
        visited = vector<vector<bool>>(n, vector<bool>(n));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!visited[i][j])
                {
                    visited[i][j] = true;
                    DFS(check, i, j, map[i][j]);
                    ans[t]++;
                }
            }
        }
        check = true;
    }
    cout << ans[0] << " " << ans[1];

    return 0;
}