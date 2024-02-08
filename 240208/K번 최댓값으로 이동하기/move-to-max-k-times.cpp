#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k;
    cin >> n >> k;
    vector<vector<int>> map(n+1, vector<int>(n+1));
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> map[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    for(int i=0; i<k; i++)
    {
        queue<pair<int, int>> q;
        vector<vector<int>> visit(n+1, vector<int>(n+1));
        q.push({x, y});
        visit[x][y] = 1;
        int maxnow = 0;
        int tx = x;
        int ty = y;
        while(!q.empty())
        {
            pair<int, int> temp = q.front();
            q.pop();
            if(map[temp.first][temp.second] < map[x][y])
            {
                if(map[temp.first][temp.second] > maxnow)
                {
                    maxnow = map[temp.first][temp.second];
                    tx = temp.first;
                    ty = temp.second;
                }
                else if(map[temp.first][temp.second] == maxnow)
                {
                    if(tx >= temp.first && tx >= temp.second)
                    {
                        tx = temp.first;
                        ty = temp.second;
                    }
                }
            }
            for(int j=0; j<4; j++)
            {
                int dirx = temp.first + dirs[j][0];
                int diry = temp.second + dirs[j][1];
                if(1 <= dirx && dirx <= n && 1 <= diry && diry <= n)
                {
                    if(!visit[dirx][diry] && map[dirx][diry] < map[x][y])
                    {
                        q.push({dirx, diry});
                        visit[dirx][diry] = 1;
                    }
                }
            }
        }
        x = tx;
        y = ty;
    }

    cout << x << " " << y;

    return 0;
}