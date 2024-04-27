#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt, ans = 0;
bool separate = false;
vector<vector<int>> map, temp, dirs ={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<bool>> visited;

void DFS(int x, int y)
{
    for(int i=0; i<4; i++)
    {
        int dirx = x + dirs[i][0];
        int diry = y + dirs[i][1];
        if(0 <= dirx && dirx < n && 0 <= diry && diry < m)
        {
            if(map[dirx][diry] !=0 && !visited[dirx][diry]) 
            {
                visited[dirx][diry] = true;
                DFS(dirx, diry);
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

    while(true)
    {
        cnt = 0;
        visited = vector<vector<bool>>(n, vector<bool>(m));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(map[i][j] != 0 && !visited[i][j]) 
                {
                    visited[i][j] = true;
                    DFS(i, j);
                    cnt++;
                }
            }
        }
        if(cnt > 1) break;

        temp = vector<vector<int>>(n, vector<int>(m));
        visited = vector<vector<bool>>(n, vector<bool>(m));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(map[i][j] != 0)
                {
                    int now = map[i][j];
                    for(int k=0; k<4; k++)
                    {
                        int dirx = i + dirs[k][0];
                        int diry = j + dirs[k][1];
                        if(0<= dirx && dirx < n && 0 <= diry && diry < m)
                        {
                            if(map[dirx][diry] == 0) now--;
                        }
                    }
                    if(now <= 0) temp[i][j] = 0;
                    else temp[i][j] = now;
                }
            }
        }

        map = temp;
        ans++;
    }
    cout << ans;

    return 0;
}