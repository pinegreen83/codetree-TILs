#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, cnt;
bool isShrink;
queue<pair<int, int>> q;
vector<vector<int>> map, dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<bool>> visited, blocks;

bool isin(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

void shrink(int x, int y)
{
    for(int d=0; d<4; d++)
    {
        int dirx = x + dirs[d][0];
        int diry = y + dirs[d][1];
        if(isin(dirx, diry) && !visited[dirx][diry])
        {
            if(map[dirx][diry] == 1)
            {
                visited[dirx][diry] = true;
                shrink(dirx, diry);
            }
            else 
            {
                if(blocks[dirx][diry] && map[x][y] == 1)
                {
                    cnt++;
                    map[x][y] = 0;
                    isShrink = true;
                }
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    map = vector<vector<int>>(n, vector<int>(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++) cin >> map[i][j];
    }

    int time = 0, before = 0;
    while(true)
    {
        blocks = vector<vector<bool>>(n, vector<bool>(m));
        before = cnt;
        cnt = 0;
        time++;
        isShrink = false;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(map[i][j] == 0)
                {
                    q.push({i, j});
                    blocks[i][j] = true;
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int d=0; d<4; d++)
                        {
                            int dirx = x + dirs[d][0];
                            int diry = y + dirs[d][1];
                            if(isin(dirx, diry) && map[dirx][diry] == 0)
                            {
                                if(!blocks[dirx][diry])
                                {
                                    q.push({dirx, diry});
                                    blocks[dirx][diry] = true;
                                }
                            }
                        }
                    }
                }
                break;
            }
        }

        visited = vector<vector<bool>>(n, vector<bool>(m));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(map[i][j] == 1 && !visited[i][j]) 
                {
                    visited[i][j] = true;
                    shrink(i, j);
                }
            }
        }

        if(!isShrink) 
        {
            cout << time-1 << "\n" << before;
            break;
        }
    }

    return 0;
}